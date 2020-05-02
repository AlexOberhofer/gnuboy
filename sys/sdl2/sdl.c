/*
 * sdl.c
 * sdl 2 interfaces -- based on sdl.c 
 *
 * (C) 2001 Damian Gryski <dgryski@uwaterloo.ca>
 * (C) 2020 Alex Oberhofer <alexmoberhofer@gmail.com>
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


/* TODO: Really need to clean this up - this will break if you rebind the keys.*/
void ev_poll()
{
	event_t ev;
	SDL_Event event;

	while (SDL_PollEvent(&event)){

    	if (event.type == SDL_QUIT){
        	exit(1);
    	}
    

	if(event.type == SDL_KEYDOWN){

        uint32_t key = event.key.keysym.scancode;

        switch(key)
        {
            case SDL_SCANCODE_RETURN: ev.type = EV_PRESS; ev.code = K_ENTER; ev_postevent(&ev); break;  
			case SDL_SCANCODE_A: ev.type = EV_PRESS; ev.code = K_LEFT; ev_postevent(&ev); break; 
			case SDL_SCANCODE_D: ev.type = EV_PRESS; ev.code = K_RIGHT; ev_postevent(&ev); break; 
			case SDL_SCANCODE_S: ev.type = EV_PRESS; ev.code = K_DOWN; ev_postevent(&ev); break; 
			case SDL_SCANCODE_W: ev.type = EV_PRESS; ev.code = K_UP; ev_postevent(&ev); break; 
			case SDL_SCANCODE_Q: ev.type = EV_PRESS; ev.code = 'q'; ev_postevent(&ev); break;
			case SDL_SCANCODE_E: ev.type = EV_PRESS; ev.code = 'e'; ev_postevent(&ev); break;  
        }

    } else if (event.type == SDL_KEYUP){
        
        uint32_t key = event.key.keysym.scancode;
        
        switch(key)
        {
            case SDL_SCANCODE_RETURN: ev.type = EV_RELEASE; ev.code = K_ENTER; ev_postevent(&ev); break; 
			case SDL_SCANCODE_A: ev.type = EV_RELEASE; ev.code = K_LEFT; ev_postevent(&ev); break; 
			case SDL_SCANCODE_D: ev.type = EV_RELEASE; ev.code = K_RIGHT; ev_postevent(&ev); break;
			case SDL_SCANCODE_S: ev.type = EV_RELEASE; ev.code = K_DOWN; ev_postevent(&ev); break;
			case SDL_SCANCODE_W: ev.type = EV_RELEASE; ev.code = K_UP; ev_postevent(&ev); break;   
			case SDL_SCANCODE_Q: ev.type = EV_RELEASE; ev.code = 'q'; ev_postevent(&ev); break; 
			case SDL_SCANCODE_E: ev.type = EV_RELEASE; ev.code = 'e'; ev_postevent(&ev); break;
        }
    }
}
		
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








