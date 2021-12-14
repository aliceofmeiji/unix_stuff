#include <SDL2/SDL.h>
#include <immintrin.h>
#include <stdlib.h>
#include <stdio.h>

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

int main()
{
	SDL_Window* window = NULL;
	SDL_Surface* screenSurface = NULL;
	SDL_Surface* imageSurface = NULL;
	SDL_Event e;	

	if(SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
	}
	else
	{
		window = SDL_CreateWindow
		(
			"Teste SDL", 
			SDL_WINDOWPOS_UNDEFINED, 
			SDL_WINDOWPOS_UNDEFINED, 
			SCREEN_WIDTH, 
			SCREEN_HEIGHT, 
			SDL_WINDOW_SHOWN
		);
		if(window == NULL)
		{
			printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
		}
		else
		{
			screenSurface = SDL_GetWindowSurface(window);
			/*SDL_FillRect
			(
				screenSurface, 
				NULL, 
				SDL_MapRGB(screenSurface->format, 0xFF, 0xFF, 0xFF)
			);*/
			imageSurface = SDL_LoadBMP("sable.bmp");
			if(imageSurface == NULL)
			{
				printf("%s\n", SDL_GetError());
			}
			SDL_BlitSurface(imageSurface, NULL, screenSurface, NULL);
			SDL_UpdateWindowSurface(window);
			SDL_Delay(2000);
		}
	}
	SDL_DestroyWindow(window);
	SDL_Quit();
	return 0;
}
