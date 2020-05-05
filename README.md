# GNUBoy SDL2 Port

# Overview 

My personal fork for experimentation. Based on GNUBoy and licensed under GPLv2

# Screenshots
<p align="center">
  <h3 align="center">Coming Soon<h3>
</p>

# Status

A working SDL2 build can be generated from the sdl2 makefile. A build of the 1.2 sdl port will likely come back as well.

## Whats been done

- Builds on linux

- SDL2 control implementation (currently not rebindable)

- SDL1.2 rendering ported to SDL2


## Todo

- Porting: The codebase is currently buildable on Windows/MacOS/*nix. I have built the SDL2 version of the codebase on each of those platforms, but I have not yet provided build scripts or releases for multiplatform. The SDL2 version only currently works on linux.

- Add hardware accelerated to rendering


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

### Cinoop

CTurt - [Github](https://github.com/CTurt)

## Acknowledgements

Cinoop Project 

* [Github] (https://github.com/CTurt/Cinoop) 

* [Website] (https://cturt.github.io/cinoop.html)

GNUBoy

* Thank you to the original GNUBoy developers. Please see the history branch for their versions. Legacy documentation can be found in the docs folder.