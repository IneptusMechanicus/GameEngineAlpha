#include "SDLFuncs.h"
#include <stdio.h>
#include <SDL.h>

using namespace SDLOGL;

int main(int argv, char *args[])
{
	SDL_Window *win = NULL;
	SDL_Surface *surf = NULL;
	SDL_Surface *img = NULL;

	
	SDLFuncs::windowInit("Function Test",20, 35, 1000, 1000, win, surf);
	return 0;
}