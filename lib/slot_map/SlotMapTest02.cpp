#include <array>
#include <gtest/gtest.h>
#include <slot_map.h>
#include <unordered_set>

// Note: You could skip slow tests by using "SlotMapTest --gtest_filter=-SlotMapTest.*_Slow"
TEST(SlotMapTest, IdCollisions_Slow)
{
    static const int kNumberOfIds = 1024;
    std::vector<dod::slot_map<int>::key> ids;
    ids.resize(kNumberOfIds);

    dod::slot_map<int> slotMap;
    for (size_t i = 0; i < ids.size(); i++)
    {
        ids[i] = slotMap.emplace(int(113 + i));
    }

    for (size_t i = 0; i < ids.size(); i++)
    {
        EXPECT_TRUE(slotMap.has_key(ids[i]));
    }

    for (size_t i = 0; i < ids.size(); i++)
    {
        slotMap.erase(ids[i]);
    }

    std::unordered_set<dod::slot_map<int>::key> idsToTest;
    for (size_t i = 0; i < ids.size(); i++)
    {
        idsToTest.emplace(ids[i]);
        EXPECT_FALSE(slotMap.has_key(ids[i]));
    }

    EXPECT_EQ(idsToTest.size(), ids.size());
    EXPECT_EQ(slotMap.size(), 0u);

#ifdef _DEBUG
    static const int kNumberOfIterations = 300000;
#else
    static const int kNumberOfIterations = 5000000;
#endif

    static const int kNumberOfTempIds = 1024;
    std::array<dod::slot_map<int>::key, kNumberOfTempIds> tempIds;

    size_t numAllocationsChecked = 0;
    for (size_t iter = 1; iter <= kNumberOfIterations; iter++)
    {
        if ((iter % 8839) == 0 || (iter + 1) == kNumberOfIterations || (iter == 1))
        {
            printf("Iteration: %d (%3.2f%%)              \r", int(iter), 100.0f * double(iter) / double(kNumberOfIterations));
        }

        for (size_t j = 0; j < kNumberOfTempIds; j++)
        {
            numAllocationsChecked++;
            auto id = slotMap.emplace(int(j + 7));
            tempIds[j] = id;

            // check for collisions
            auto it = idsToTest.find(id);
            ASSERT_EQ(it, idsToTest.end());
        }

        for (size_t j = 0; j < kNumberOfTempIds; j++)
        {
            EXPECT_TRUE(slotMap.has_key(tempIds[j]));
            slotMap.erase(tempIds[j]);
        }
    }
    printf("\n");
    printf("Num allocations: %d\n", int(numAllocationsChecked));

    slotMap.emplace(33);
    EXPECT_EQ(slotMap.size(), 1u);

    for (size_t i = 0; i < ids.size(); i++)
    {
        EXPECT_FALSE(slotMap.has_key(ids[i]));
    }

    for (size_t i = 0; i < ids.size(); i++)
    {
        EXPECT_EQ(slotMap.get(ids[i]), nullptr);
    }

    for (size_t i = 0; i < ids.size(); i++)
    {
        std::optional<int> r = slotMap.pop(ids[i]);
        EXPECT_EQ(r.has_value(), false);
    }

    auto stats = slotMap.debug_stats();

    printf("Pages: total: %d, active: %d, inactive: %d\n", int(stats.numPagesTotal), int(stats.numActivePages),
           int(stats.numInactivePages));
    printf("Items: total: %d, alive: %d, tombstone: %d, inactive: %d\n", int(stats.numItemsTotal), int(stats.numAliveItems),
           int(stats.numTombstoneItems), int(stats.numInactiveItems));

    slotMap.clear();
    slotMap.reset();
}
