#define SDL_DISABLE_IMMINTRIN_H 1
#include <SDL2/SDL.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char **argv)
{
	char red, grn, blu;
	int width, height, i, j;
	SDL_Event event;
	SDL_Window *window = NULL;
	SDL_Renderer *renderer = NULL;

	sscanf(argv[1], "%d", &width);
	sscanf(argv[2], "%d", &height);

	SDL_Init(SDL_INIT_VIDEO);
	SDL_CreateWindowAndRenderer(width, height, SDL_WINDOW_RESIZABLE, &window, &renderer);

	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
	SDL_RenderClear(renderer);

	for(i = 0; i < height; i++)
	{
		for(j = 0; j < width; j++)
		{
			red = getchar();
			grn = getchar();
			blu = getchar();
			SDL_SetRenderDrawColor(renderer, red, grn, blu, 255);
			SDL_RenderDrawPoint(renderer, j, i);
		}
	}
	SDL_RenderPresent(renderer);

	for(;;)
	{
		SDL_PollEvent(&event);
		switch(event.type)
		{
			case SDL_WINDOWEVENT:
				if (event.window.event == SDL_WINDOWEVENT_RESIZED)
				{
					SDL_SetWindowSize(window, event.window.data1, event.window.data2);
					SDL_RenderPresent(renderer);
				}
				break;

			case SDL_QUIT:
				SDL_DestroyRenderer(renderer);
				SDL_DestroyWindow(window);
				SDL_Quit();
				return 0;
				break;
		}
	}
}
