#ifndef SDLOGL
#define SDLOGL_EXPORTS __declspec(dllexport)
#else
#define SDLOGL_EXPORTS __declspec(dllimport)
#endif

#include <stdio.h>
#include <SDL.h>

namespace SDLOGL
{
	class SDLFuncs
	{
	public:
		static SDLOGL_EXPORTS bool windowInit(char *winName, int winPosX, int winPosY, int winSizeX, int winSizeY, SDL_Window *win = NULL, SDL_Surface *scrSurf = NULL);

		static SDLOGL_EXPORTS bool loadBMP(char *fileDir, SDL_Surface *imgSurf = NULL);
	};
}