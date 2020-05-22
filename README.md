# GNUBoy SDL2 Port

# Overview 

My personal fork for experimentation. Based on GNUBoy and licensed under GNU GPLv2

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

# Status

A working SDL2 build can be generated from the sdl2 makefile. 

## Whats been done

- Builds on linux

- SDL2 control implementation (currently not rebindable)

- SDL1.2 rendering ported to SDL2


## Todo

- Porting: The codebase is currently buildable on Windows/MacOS/*nix. I have built the SDL2 version of the codebase on each of those platforms, but I have not yet provided build scripts or releases for multiplatform. The SDL2 version only currently works on linux.

- Add hardware acceleration to rendering (textures vs surfaces)

- Add scaling to SDL2 port


# Building

This project requires GCC and SDL2 to build for linux. A Makefile has been provided.

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
$ make -f Makefile.sdl2
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