#include "SDLFuncs.h"
#include <stdio.h>
#include <SDL.h>

namespace SDLOGL
{
	//Initialize window
	bool SDLFuncs::windowInit(char *winName, int winPosX, int winPosY, int winSizeX, int winSizeY, SDL_Window *win, SDL_Surface *scrSurf)
	{
		bool quit = false;
		SDL_Event e;
		//Check if initialized
		if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
		{
			printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
			return false;
		}
		else
		{
			while (!quit)
			{
				win = SDL_CreateWindow(winName, winPosX, winPosY, winSizeX, winSizeY, SDL_WINDOW_SHOWN);
				if (win == NULL)
				{
					printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
					return false;
				}
				else scrSurf = SDL_GetWindowSurface(win);
				while (SDL_PollEvent(&e) != 0)
				{
					//User requests quit
					if (e.type == SDL_QUIT)
					{
						quit = true;
					}
				}
				SDL_Delay(1);
			}
		}
		return true;
	}

	//Load BMP Image
	bool SDLFuncs::loadBMP(char *bmpFileDir, SDL_Surface *imgSurf)
	{
		imgSurf = SDL_LoadBMP(bmpFileDir);
		//Check for errors
		if (imgSurf == NULL)
		{
			printf("Unable to load image %s! SDL Error: %s\n", bmpFileDir, SDL_GetError());
			return false;
		}
		return true;
	}
}