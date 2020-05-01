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


SDL_Surface *surface;
SDL_Window *window;
SDL_Surface *window_surface;
SDL_Texture *texture;
SDL_Renderer *renderer;

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

	if (!vmode[0] || !vmode[1])
	{
		vmode[0] = 160 * 1;
		vmode[1] = 144 * 1;
	}


	if(SDL_Init(SDL_INIT_EVERYTHING) < 0){
        printf("SDL_Init failed: %s\n", SDL_GetError());
        exit(1);
    } else {
        window = SDL_CreateWindow("GNUBoy SDL2", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, vmode[0], vmode[1], NULL);
        renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
        SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "0");
        texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGB24, SDL_TEXTUREACCESS_STREAMING, vmode[0], vmode[1]);
		/*surface = SDL_CreateRGBSurface(0, vmode[0], vmode[1], vmode[2], 0, 0, 0, 0);*/
		surface = SDL_GetWindowSurface(window);
    }

	SDL_LockSurface(surface);

	fb.w = surface->w;
	fb.h = surface->h;
	fb.pelsize = surface->format->BytesPerPixel;
	fb.pitch = surface->pitch;
	fb.indexed = fb.pelsize == 1;
	fb.ptr = surface->pixels;
	fb.cc[0].r = surface->format->Rloss;
	fb.cc[0].l = surface->format->Rshift;
	fb.cc[1].r = surface->format->Gloss;
	fb.cc[1].l = surface->format->Gshift;
	fb.cc[2].r = surface->format->Bloss;
	fb.cc[2].l = surface->format->Bshift;
	
	SDL_UnlockSurface(surface);

	fb.enabled = 1;
	fb.dirty = 0;

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
	SDL_DestroyWindow(window);
	SDL_UnlockSurface(surface);
	SDL_Quit();
}

void vid_settitle(char *title)
{
	
}

void vid_begin()
{
		SDL_LockSurface(surface);
		fb.ptr = surface->pixels;
}

void vid_end()
{

	SDL_UnlockSurface(surface);
	/*SDL_RenderClear(renderer);
	SDL_RenderCopy(renderer, texture, NULL, NULL);
	SDL_RenderPresent(renderer);*/
	SDL_UpdateWindowSurface(window);
	
}








