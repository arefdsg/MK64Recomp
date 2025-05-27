#include <ultra64.h>
#include <macros.h>
#include <segments.h>
#include <common_structs.h>
#include "math_util.h"
#include "ceremony_and_credits.h"
#include "code_800029B0.h"
#include "code_80280000.h"
#include "objects.h"
#include "main.h"
#include "camera.h"
#include "audio/external.h"
#include <sounds.h>
#include "podium_ceremony_actors.h"
#include "menu_items.h"
#include "code_80057C60.h"
#include "defines.h"
#include "patches.h"
#include "ceremony_patches.h"

void func_80283CA8_2(UNUSED CinematicCamera* camera) {
    func_800CA008(0, 3);
}

void func_80283CD0_2(UNUSED CinematicCamera* camera) {
    if (D_800DC5E4 == 0) {
        func_800CA008(0, 2);
    }
}

void wrap_func_800CA0CC_2(UNUSED CinematicCamera* camera) {
    func_800CA0CC();
}

void func_80283BF0_2(UNUSED CinematicCamera* camera) {
    func_800C8EF8(0x1A);
}

/**
 * Played after receiving trophy.
 */
void play_sound_congratulation_2(UNUSED CinematicCamera* camera) {
    play_sound2(SOUND_CEREMONY_CONGRATULATION);
}

/**
 * Played in ceremony opening with balloons.
 */
void play_sound_balloon_pop_2(UNUSED CinematicCamera* camera) {
    play_sound2(SOUND_CEREMONY_BALLOON_POP);
}


void play_sound_fish_1(UNUSED CinematicCamera* camera) {
    play_sound2(SOUND_CEREMONY_FISH);
}

void play_sound_fish_2_1(UNUSED CinematicCamera* camera) {
    play_sound2(SOUND_CEREMONY_FISH_2);
}

void play_sound_shoot_trophy_2(UNUSED CinematicCamera* camera) {
    play_sound2(SOUND_CEREMONY_SHOOT_TROPHY);
}

void play_sound_podium_2(UNUSED CinematicCamera* camera) {
    play_sound2(SOUND_CEREMONY_PODIUM);
}

/**
 * Played in background nearly the entire ceremony
 * Begins again or plays louder once the trophy appears.
 */
void play_sound_trophy_2(UNUSED CinematicCamera* camera) {
    play_sound2(SOUND_CEREMONY_TROPHY);
}

/**
 * Played at beginning of credits.
 */
void play_sound_welcome_2(UNUSED CinematicCamera* camera) {
    if (D_800DC5E4 == 0) {
        play_sound2(SOUND_INTRO_WELCOME);
    }
}

/**
 * End of credits farewell.
 * "Hey, you're very good. See you next time!"
 */
void play_sound_farewell_2(UNUSED CinematicCamera* arg0) {
    play_sound2(SOUND_CREDITS_FAREWELL);
}

void wrap_func_8028100C_2(UNUSED CinematicCamera* camera) {
    func_8028100C(-0xC6C, 0xD2, -0x1EF);
}

void wrap_func_800CB134_2(UNUSED CinematicCamera* camera) {
    func_800CB134();
}

void func_80283C78_2(UNUSED CinematicCamera* arg0) {
    if (D_800DC5E4 == 0) {
        func_800C8EF8(0x1C);
    }
}

void animation_apears_sliding_borders_2(UNUSED CinematicCamera* camera) {
    gOrderedSizeSlidingBorders = 52.0f;
}

void animation_disapears_sliding_borders_2(UNUSED CinematicCamera* camera) {
    gOrderedSizeSlidingBorders = 0.0f;
}

void wrap_func_80092C80_2(UNUSED CinematicCamera* camera) {
    func_80092C80();
}

void wrap_func_80280FFC_2(UNUSED CinematicCamera* camera) {
    func_80280FFC();
}

void reset_spline_wrap_2(UNUSED CinematicCamera* arg0) {
    reset_spline();
}

void func_802845EC_2(CinematicCamera* camera) {
    move_cinematic_camera_along_spline(camera, (struct struct_80286A04*) D_80285B90,
                                       (struct struct_80286A04*) D_80285BA8, 0);
}

void func_8028461C_2(CinematicCamera* camera) {
    func_80283240(1);
    func_80283B6C(camera);
}

void func_80283BA4_2(UNUSED CinematicCamera* camera) {
    func_800CA0B8();
    func_800C90F4(0, (gPlayerFour->characterId * 0x10) + SOUND_ARG_LOAD(0x29, 0x00, 0x80, 0x04));
    func_800CA0A0();
}

void func_80284648_2(CinematicCamera* camera) {
    cutscene_event(func_802845EC_2, camera, 0, 0);
    cutscene_event(func_8028461C_2, camera, 0x110, 0x110);
    cutscene_event(func_80283BA4_2, camera, 0x115, 0x115);
}

void func_8028454C_2(CinematicCamera* camera) {
    cutscene_event(func_80283CA8_2, camera, 0, 0);
    cutscene_event(wrap_func_800CA0CC_2, camera, 1, 1);
    cutscene_event(wrap_func_800CB134_2, camera, 0, 0);
    cutscene_event(wrap_func_80280FFC_2, camera, 0x3C, 0x3C);
    move_cinematic_camera_along_spline(camera, (struct struct_80286A04*) D_80285B18,
                                       (struct struct_80286A04*) D_80285B54, 0);
}

void func_80283D2C_2(CinematicCamera* camera) {
    gOrderedSizeSlidingBorders = 120.0f;
    cutscene_event(func_80283CA8_2, camera, 0, 0);
    cutscene_event(wrap_func_800CA0CC_2, camera, 1, 1);
    cutscene_event(func_80283BF0_2, camera, 0, 0);
    cutscene_event(play_sound_balloon_pop_2, camera, 45, 45);
    cutscene_event(play_sound_balloon_pop_2, camera, 65, 65);
    cutscene_event(play_sound_balloon_pop_2, camera, 70, 70);
    cutscene_event(play_sound_balloon_pop_2, camera, 94, 94);
    cutscene_event(play_sound_balloon_pop_2, camera, 110, 110);
    cutscene_event(play_sound_balloon_pop_2, camera, 130, 130);
    cutscene_event(play_sound_balloon_pop_2, camera, 152, 152);
    cutscene_event(play_sound_balloon_pop_2, camera, 160, 160);
    cutscene_event(wrap_func_80280FFC_2, camera, gCutScene[0].duration - 60, gCutScene[0].duration - 60);
    move_cinematic_camera_along_spline(camera, (struct struct_80286A04*) D_802856DC,
                                       (struct struct_80286A04*) D_80285718, 0);
};

void func_80283EA0_2(CinematicCamera* camera) {
    move_cinematic_camera_along_spline(camera, (struct struct_80286A04*) D_80285754,
                                       (struct struct_80286A04*) D_80285784, 0);
}

void func_80283F6C_2(CinematicCamera* camera) {
    cutscene_event(copy_player_two_in_camera, camera, 0, 0);
    cutscene_event(lerp_player_two_in_camera, camera, 0, -1);
    func_80282E58(camera, (struct struct_80282C40*) D_802857B4, 0);
}

void func_80284068_2(CinematicCamera* camera) {
    cutscene_event(copy_player_three_in_camera, camera, 0, 0);
    cutscene_event(lerp_player_three_in_camera, camera, 0, -1);
    func_80282E58(camera, (struct struct_80282C40*) D_802857CC, 0);
}


void func_80283C14_2(UNUSED CinematicCamera* camera) {
    func_800C8EF8(0x1B);
}


void func_802840C8_2(CinematicCamera* camera) {
    cutscene_event(func_80283C14_2, camera, 5, 5);

    switch (D_802876D8) {
        case 2:
            func_80283EA0_2(camera);
            break;
        case 3:
            func_80283F6C_2(camera);
            break;
        case 4:
            func_80284068_2(camera);
            break;
    }
}

void func_802842D8_2(CinematicCamera* camera) {
    move_cinematic_camera_along_spline(camera, (struct struct_80286A04*) D_802857F0,
                                       (struct struct_80286A04*) D_80285850, 0);
}

void func_80284418_2(CinematicCamera* camera) {
    cutscene_event(play_sound_podium_2, camera, 0x52, 0x52);
    cutscene_event(play_sound_podium_2, camera, 0x48, 0x48);
    cutscene_event(play_sound_podium_2, camera, 0x3D, 0x3D);
    move_cinematic_camera_along_spline(camera, (struct struct_80286A04*) D_80285A10,
                                       (struct struct_80286A04*) D_80285A4C, 0);
}

void func_80284494_2(CinematicCamera* camera) {
    cutscene_event(play_sound_fish_2_1, camera, 0x1E, 0x1E);
    cutscene_event(wrap_func_8028100C_2, camera, 0, 0);
    move_cinematic_camera_along_spline(camera, (struct struct_80286A04*) D_80285A88,
                                       (struct struct_80286A04*) D_80285AB8, 0);
}

void func_802844FC_2(CinematicCamera* camera) {
    cutscene_event(play_sound_fish_1, camera, 0x3B, 0x3B);
    move_cinematic_camera_along_spline(camera, (struct struct_80286A04*) D_80285AE8,
                                       (struct struct_80286A04*) D_80285B00, 0);
}

void func_80284184_2(CinematicCamera* camera) {
    f32 trophy;
    trophy = ((gObjectList[indexObjectList1[3]].pos[1] - camera->lookAt[1]) * 0.9f) + camera->lookAt[1];
    f32_lerp(&camera->pos[1], trophy, 0.5);
}

void func_802841E8_2(CinematicCamera* camera) {
    func_80282E58(camera, (struct struct_80282C40*) D_80285940, 0);
    vec3f_set_dupe(camera->pos, -3202.0f, 90.0f, -478.0f);
}

void func_8028422C_2(CinematicCamera* camera) {
    cutscene_event(play_sound_shoot_trophy_2, camera, 6, 6);
    cutscene_event(play_sound_trophy_2, camera, 30, 30);
    cutscene_event(func_802841E8_2, camera, 0, 0);
    cutscene_event(func_80284184_2, camera, 6, -1);
}

void func_802842A8_2(CinematicCamera* camera) {
    move_cinematic_camera_along_spline(camera, (struct struct_80286A04*) D_802858B0,
                                       (struct struct_80286A04*) D_802858C8, 0);
}

void func_80284308_2(CinematicCamera* camera) {
    Player** sp30[4] = { &gPlayerOne, &gPlayerTwo, &gPlayerThree, &gPlayerFour };
    Player* ply;
    f32 x;
    f32 y;
    f32 z;

    cutscene_event(play_sound_congratulation_2, camera, 140, 140);
    move_cinematic_camera_along_spline(camera, (struct struct_80286A04*) D_802858E0,
                                       (struct struct_80286A04*) D_802858F8, 0);

    ply = *(sp30[0] + D_802874D8.unk1D);

    x = ply->pos[0] - gPlayerOne->pos[0];
    y = ply->pos[1] - gPlayerOne->pos[1];
    z = ply->pos[2] - gPlayerOne->pos[2];

    camera->lookAt[0] += x;
    camera->lookAt[2] += z;
    camera->pos[0] += x;
    camera->pos[2] += z;
    camera->lookAt[1] += y;
    camera->pos[1] += y;
}

struct Cutscene gCutScenePatch[] = {
    { func_80283D2C_2, 330 }, { func_802840C8_2, 270 }, { func_802842D8_2, 247 },
    { func_80284418_2, 200 }, { func_80284494_2, 170 }, { func_802844FC_2, 108 },
    { func_8028422C_2, 140 }, { func_802842A8_2, 270 }, { func_80284308_2, 0x7FFF },
};

RECOMP_PATCH void func_802847CC(CinematicCamera* camera) {
    u16 sp2E;
    u16 sp2C;
    // D_802856B4 cast to u32 triggers cfc1.
    sp2E = D_80286A04[D_800DC5E4].unkC - (10 - (-(((u16) (u32) D_802856B4))));
    sp2C = D_80286A04[D_800DC5E4].unkC;

    cutscene_event(func_80283CD0_2, camera, 0, 0);
    cutscene_event(play_sound_welcome_2, camera, 8, 8);
#ifdef VERSION_EU
    cutscene_event(func_80283C78_2, camera, 134, 134);
#else
    cutscene_event(func_80283C78_2, camera, 149, 149);
#endif
    cutscene_event(reset_spline_wrap_2, camera, 0, 0);
    switch (D_80286A04[D_800DC5E4].unk0) {
        case 1:
            cutscene_event(animation_disapears_sliding_borders_2, camera, 0, -1);
            cutscene_event(wrap_func_80092C80, camera, sp2E - 0x14, sp2E - 0x14);
            break;

        case 2:
            cutscene_event(animation_apears_sliding_borders_2, camera, 0, 0);
            cutscene_event(play_sound_farewell_2, camera, 247, 247);
            move_cinematic_camera_along_spline(camera, (struct struct_80286A04*) D_80286A04[D_800DC5E4].unk4,
                                               (struct struct_80286A04*) D_80286A04[D_800DC5E4].unk8, 0);
            break;
        default:
            cutscene_event(animation_apears_sliding_borders_2, camera, 0, 0);
            cutscene_event(animation_disapears_sliding_borders_2, camera, sp2E, sp2E);
            cutscene_event(wrap_func_80092C80, camera, sp2E - 0x14, sp2E - 0x14);
            move_cinematic_camera_along_spline(camera, (struct struct_80286A04*) D_80286A04[D_800DC5E4].unk4,
                                               (struct struct_80286A04*) D_80286A04[D_800DC5E4].unk8, 0);
            break;
    }

#ifndef VERSION_EU
    if (gCCSelection == CC_EXTRA) {
        sp2C = D_80286B34[D_800DC5E4];
    }
#endif

    if (gCutsceneShotTimer == sp2C) {
        if (D_80286A04[D_800DC5E4].unk0 != 2) {
            func_80280268(D_80286A04[D_800DC5E4 + 1].unk1);
        }
    }
}

/**
 * Play the current cutscene until either gCutsceneShotTimer reaches the max time, or c->cutscene is set to 0
 */
RECOMP_PATCH void play_cutscene(CinematicCamera* camera) {
    UNUSED s32 pad[3];
    s16 cutsceneDuration;

#define CUTSCENE(id, cutscene)                               \
    case id:                                                 \
        cutsceneDuration = cutscene[sCutsceneShot].duration; \
        cutscene[sCutsceneShot].shot(camera);

    if (!camera->cutscene) {
        return;
    }
    switch (camera->cutscene) {
        CUTSCENE(2, gCutScenePatch)
        break;
        CUTSCENE(3, gCutScenePatch)
        break;
        CUTSCENE(4, gCutScenePatch)
        break;
        CUTSCENE(5, D_80285D58)
        wrap_func_800CB14C(camera);
        break;
        CUTSCENE(6, D_80286B5C)
        break;
    }

#undef CUTSCENE

    if ((cutsceneDuration != 0) && ((gCutsceneShotTimer & 0xC000) == 0)) {

        if (gCutsceneShotTimer < 16383) {
            gCutsceneShotTimer++;
        }
        if (gCutsceneShotTimer == cutsceneDuration) {
            sCutsceneShot++;
            gCutsceneShotTimer = 0;
            reset_spline();
        }
    } else {
        if (gCutsceneShotTimer & 0x4000) {
            gCutsceneShotTimer = 0;
            reset_spline();
        } else {
            D_802876D8 = 0;
            sCutsceneShot = 0;
            gCutsceneShotTimer = 0;
            reset_spline();
        }
    }
}

RECOMP_PATCH s32 move_cinematic_camera_along_spline(CinematicCamera* camera, struct struct_80286A04* arg1,
                                       struct struct_80286A04* arg2, s32 arg3) {
    s32 res;

    cutscene_event(reset_spline_wrap_2, camera, 0, 0);
    func_80282C40(D_80287818, (struct struct_80282C40*) arg1, arg3);
    func_80282C40(D_80287998, (struct struct_80282C40*) arg2, arg3);

    if (0) {}; // debug stub?

    res = move_point_along_spline(camera->lookAt, &camera->unk18, D_80287818, &sCutsceneSplineSegment,
                                  &sCutsceneSplineSegmentProgress) |
          move_point_along_spline(camera->pos, &camera->unk18, D_80287998, &sCutsceneSplineSegment,
                                  &sCutsceneSplineSegmentProgress);
    return res;
}

void unused_80280FA0_2(UNUSED CeremonyActor* actor) {
}

void unused_80280FA8_2(UNUSED CeremonyActor* actor) {
}

/**
 * Spawns an aerial shell that ascends into the sky.
 * (note that the explode effect is a different actor)
 */
void firework_cone_update_and_spawn_burst_2(Firework* cone) {
    if (cone->unk44 < 30) {
        cone->pos[1] += 2.5f;
        cone->pos[0] += random_who_knows(0.2f);
        cone->pos[2] += random_who_knows(0.2f);
    } else if (cone->unk2C == 4) {
        Firework* burst = (Firework*) new_actor(&initCone);
        burst->pos[0] = cone->pos[0];
        burst->pos[1] = cone->pos[1];
        burst->pos[2] = cone->pos[2];
        burst->unk30 = fireworkConeColour[cone->unk48];
        burst->unk3C = 0xFF;
        burst->unk40 = -0x11;
        burst->unk44 = 0x64;
        burst->unk34 = 1.8700001f;
        burst->unk38 = 1.8700001f;
    }
}

void firework_update_2(Firework* actor) {
    s32 i;
    Vec3f pos;
    if (actor->unk44 < 30) {
        for (i = 0; i < 10; i++) {
            pos[0] = actor->pos[0];
            pos[1] = actor->pos[1] - i * 2;
            pos[2] = actor->pos[2];
            render_fireworks(pos, ((10 - i) / 10.0f) * 2, fireworkColour[actor->unk48],
                             (((((30 - actor->unk44) * 100)) / 30.0f)));
        }

    } else {
        if (actor->unk2C < 5) {
            actor->unk3C += actor->unk40 * 2;
            actor->unk34 += actor->unk38 * 2;
        } else {
            actor->unk3C += actor->unk40 / (1.0f + (((actor->unk2C * 7) - 0x23) / 10.0f));
            actor->unk34 += actor->unk38 / (1.0f + (((actor->unk2C * 7) - 0x23) / 10.0f));
            if (actor->unk3C < 0) {
                actor->unk3C = 0;
            }
        }
        actor->unk2C += 1;
        if (((actor->unk3C > 0) && ((actor->unk34 > 0.0f))) || (actor->unk2C < 30)) {
            render_fireworks(actor->pos, actor->unk34, actor->unk30, (s16) actor->unk3C);
        } else {
            actor->isActive = 0;
        }
    }
    actor->unk44 += 1;
}

void balloon_update_2(CeremonyActor* actor) {
    render_balloon(actor->pos, 1.0f, actor->unk2E, actor->unk2C);
    actor->pos[1] += 0.8f;
    actor->unk2E = sins(actor->unk30) * actor->unk34;
    actor->unk30 += actor->unk32;
    actor->timer++;

    // Delete actor
    if (actor->timer > 800) {
        actor->isActive = 0;
    }
    if (D_802874B0[13] == 1) {
        actor->isActive = 0;
    }
}

void* sUpdatePatch[][3] = {
    // Dummy actor
    { unused_80280FA8_2, unused_80280FA0_2, 0 },
    // Balloon
    { unused_80280FA8_2, balloon_update_2, 0 },
    // Firework Cone
    { unused_80280FA8_2, firework_update_2, 0 },
    // Firework Burst
    { firework_cone_update_and_spawn_burst_2, 0, firework_update_2 },
};

RECOMP_PATCH void update_actors_loop(void) {
    void (*func)(void*);
    s32 i;
    s32 j;
    spawn_timer();
    D_802874B0[16] = 0;

    // Why do we loop over the actor list three times?
    // Actors don't with no loop. fireworks don't spawn if the iterator is 2.
    for (i = 0; i < 3; i++) {
        CeremonyActor* actor = sPodiumActorList;
        for (j = 0; j < 200; j++) {
            if (actor->isActive & 1) {

                func = sUpdatePatch[actor->type][i];

                if (func != 0) {
                    func(actor);
                }
            }
            actor++;
        }
    }
}