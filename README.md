# Mario Kart 64: Recompiled
Mario Kart 64: Recompiled is a project that uses [N64: Recompiled](https://github.com/Mr-Wiseguy/N64Recomp) to **statically recompile** Mario Kart 64 into a native port with many new features, enhancements, and extensive mod support. This project uses [RT64](https://github.com/rt64/rt64) as the rendering engine to provide graphical enhancements.

If you're here you're most likely looking for [https://github.com/sonicdcer/MarioKart64Recomp](https://github.com/sonicdcer/MarioKart64Recomp) instead, which has no relation to here despite using the same game and software.

## Table of Contents
* [System Requirements](#system-requirements)
* [Linux and Steam Deck Support](#linux-and-steam-deck-support)
* [Known Issues](#known-issues)
* [Building](#building)
* [Libraries Used and Projects Referenced](#libraries-used-and-projects-referenced)

## System Requirements
A GPU supporting Direct3D 12.0 (Shader Model 6), Vulkan 1.2, or Metal Argument Buffers Tier 2 support is required to run this project. The oldest GPUs that should be supported for each vendor are:
* GeForce GT 630
* Radeon HD 7750 (the one from 2012, not to be confused with the RX 7000 series) and newer
* Intel HD 510 (Skylake)
* A Mac with Apple Silicon or an Intel 7th Gen CPU with MacOS 13.0+

On x86-64 PCs, a CPU supporting the AVX instruction set is also required (Intel Core 2000 series or AMD Bulldozer and newer). ARM64 builds will work on any ARM64 CPU.

If you have issues with crashes on startup, make sure your graphics drivers are fully up to date. 


#### Linux and Steam Deck Support
A Linux binary as well as a Flatpak is available for playing on most up-to-date distros, including on the Steam Deck.

To play on Steam Deck, extract the Linux build onto your deck. Then, in desktop mode, right click the MK64Recompiled executable file and select "Add to Steam". From there, you can return to Gaming mode and configure the controls as needed.

## Known Issues
* Overlays such as MSI Afterburner and other software such as Wallpaper Engine can cause performance issues with this project that prevent the game from rendering correctly. Disabling such software is recommended.
* The game freezes when opening the controls while in-game.
* Balloons make the game lag.
* Minor graphics issues during race results.

## Building
Instructions on how to build this project can be found in the [BUILDING.md](BUILDING.md) file.

## Libraries Used and Projects Referenced
* [RT64](https://github.com/rt64/rt64) for the project's rendering engine
* [RmlUi](https://github.com/mikke89/RmlUi) for building the menus and launcher
* [lunasvg](https://github.com/sammycage/lunasvg) for SVG rendering, used by RmlUi
* [FreeType](https://freetype.org/) for font rendering, used by RmlUi  
* [moodycamel::ConcurrentQueue](https://github.com/cameron314/concurrentqueue) for semaphores and fast, lock-free MPMC queues
* [Gamepad Motion Helpers](https://github.com/JibbSmart/GamepadMotionHelpers) for sensor fusion and calibration algorithms to implement gyro aiming
* [Majora's Mask Decompilation](https://github.com/zeldaret/mm) for headers and some function definitions, used for making patches or some enhancements
* [Mario Kart 64 Decompilation](https://github.com/n64decomp/mk64)  for headers and some function definitions, used for making patches
* [Zelda 64: Recompiled](https://github.com/Zelda64Recomp/Zelda64Recomp)
* [Ares emulator](https://github.com/ares-emulator/ares) for RSP vector instruction reference implementations, used in RSP recompilation
