# GNUBoy SDL2 Port

# Overview 

My personal fork for experimentation. Based on GNUBoy and licensed under GNU GPLv2

SDL2 port now working on Linux (Tested on Ubuntu and Manjaro... and Windows Linux Subsystem - though there are timing issues with SDL2)

# Screenshots

<div align="center">

|  GB | GBC  |
|---|---|
| <img alt="Dr Mario" src="https://github.com/AlexOberhofer/gnuboy/raw/refactor/docs/drmario.PNG"> | <img alt="Lemmings" src="https://github.com/AlexOberhofer/gnuboy/raw/refactor/docs/lemmings.PNG"> |
|<img alt="Ms Pac Man" src="https://github.com/AlexOberhofer/gnuboy/raw/refactor/docs/mspacman.PNG">|<img alt="Pacman" src="https://github.com/AlexOberhofer/gnuboy/raw/refactor/docs/pacman.PNG">| 
|<img alt="Super Mario :amd" src="https://github.com/AlexOberhofer/gnuboy/raw/refactor/docs/supermarioland.PNG">|<img alt="Pokemon Yellow" src="https://github.com/AlexOberhofer/gnuboy/raw/refactor/docs/pkmnyellow.PNG">| 
|   <img alt="Tetris" src="https://github.com/AlexOberhofer/gnuboy/raw/refactor/docs/tetris.PNG">|<img alt="Pokemom Crystal" src="https://github.com/AlexOberhofer/gnuboy/raw/refactor/docs/pkmncrystal.PNG">|
|<img alt="Zelda" src="https://github.com/AlexOberhofer/gnuboy/raw/refactor/docs/zelda.PNG"> |<img alt="Super Mario Deluxe" src="https://github.com/AlexOberhofer/gnuboy/raw/refactor/docs/supermariodeluxe.PNG"> |

</div>

# Performance

The original core of GNUBoy is mainly unmodified except for a number of bugfixes I have ported into this fork. 

## SDL2GNUBoy v1.0 Metrics

Here are a few demos running game intro loops and a unix process monitor (htop):

*Note:* Captures are from a Manjaro VM running on VMWare on Windows 10 <br>
<center> <h4>Classic Gameboy: Pokemon Red</h4><br>
<img alt="Zelda" src="https://github.com/AlexOberhofer/gnuboy/raw/master/docs/red.gif"></center><br>
<center> <h4>Gameboy Color: Pokemon Crystal</h4><br>
<img alt="Zelda" src="https://github.com/AlexOberhofer/gnuboy/raw/master/docs/crystal.gif"></center><br>



## Legacy Metrics

Pre - fork GNUBoy performance metrics:

*Note*: The ASM code has now been removed from this repository

```
  PERFORMANCE

Here are some performance estimates i've gathered (given in percent
cpu utilization, running at full 60 fps)...

                                 Optimized C        Assembly
  AMD K6-2/450                       12%               8%
  Pentium/75                     (too slow)           70%
  SGI O2                             25%            (no asm)
  SGI Indy                           70%            (no asm)
  Sun Ultra60                       3-20%           (no asm)
  IBM S/390                      about 0.3%         (no asm)

Note that these figures were computed before sound was implemented.
Until the sound code is further optimized, gnuboy may run somewhat
slower than these numbers suggest.
```

# Status

A working SDL2 build can be generated from the provided makefile. This is the build file I use for linux

## Whats been done

- Builds and Runs on linux (Tested and developed on Manjaro)

- SDL2 control implementation (currently not rebindable)

- SDL1.2 rendering ported to SDL2 (Now uses gpu if possible and supports scaling)

- SDL1.2 sound ported to SDL2 (Needs a bit of work but its functional)


## Todo

- Porting: The codebase is currently buildable on Windows/MacOS/*nix. I have built the SDL2 version of the codebase on each of those platforms, but I have not yet provided build scripts or releases for multiplatform. The SDL2 version only currently works on linux.


# Building

This project requires GCC and SDL2 to build for linux. A Makefile has been provided.

Install SDL2 development libraries (Ubuntu):

```
$ apt-get install libsdl2-dev
```

Clone github repository: 

```
$ git clone https://github.com/AlexOberhofer/gnuboy.git
```

Enter project directory:

```
$ cd gnuboy
```

Build:

```
$ make 
```

Run:

```
$ ./sdl2gnuboy ./rom
```


# Controls

Controls are as follows:

```
P - PAUSE GAME (currently unsupported)
```

```
R - RESUME GAME (currently unsupported)
```

```
ESC - QUIT 
```

```
W - UP
```

```
S - DOWN
```

```
A - LEFT 
```

```
D - RIGHT 
```

```
Q - A
```

```
E - B
```

```
ENTER - START
```

```
BACKSPACE - SELECT
```


## Developers

### SDL2 GNUBoy

Alex Oberhofer

## Acknowledgements

Cinoop Project 

CTurt - [Github](https://github.com/CTurt)

* [Github] (https://github.com/CTurt/Cinoop) 

* [Website] (https://cturt.github.io/cinoop.html)

GNUBoy

* Thank you to the original GNUBoy developers. Please see the history branch for their versions. Legacy documentation can be found in the docs folder.

* [Website] (https://sourceforge.net/projects/gnuboy/)