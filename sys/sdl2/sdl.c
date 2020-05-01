/*
 * sdl.c
 * sdl interfaces -- based on svga.c 
 *
 * (C) 2001 Damian Gryski <dgryski@uwaterloo.ca>
 * Joystick code contributed by David Lau
 *
 * Licensed under the GPLv2, or later.
 */

#include <stdlib.h>
#include <stdio.h>

#include <SDL2/SDL.h>


#include "fb.h"
#include "input.h"
#include "rc.h"

struct fb fb;

static int vmode[3] = { 0, 0, 16 };



/* keymap - mappings of the form { scancode, localcode } - from sdl/keymap.c */
extern int keymap[][2];

static int mapscancode()
{
	return 0;
}


static void joy_init()
{
	
}

static void overlay_init()
{
	
}

void vid_init()
{
	
	
}


void ev_poll()
{
	
}

void vid_setpal(int i, int r, int g, int b)
{

}

void vid_preinit()
{
}

void vid_close()
{

}

void vid_settitle(char *title)
{
	
}

void vid_begin()
{

}

void vid_end()
{

}








