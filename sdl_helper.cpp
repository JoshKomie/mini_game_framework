#include "sdl_helper.h"
#include <SDL_Image.h>
#include <SDL_ttf.h>
#include <stdio.h>

bool init_sdl()
{
	bool success = true;
	if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
	{
		printf( "SDL could not initialize! SDL Error: %s\n", SDL_GetError() );
		success = false;
	}
  /* if( !SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "0" ) ) */
  /* { */
  /*   printf( "Warning: Linear texture filtering not enabled!" ); */
  /* } */
  return success;
}

SDL_Window *create_window(int w, int h)
{
		SDL_Window *window = SDL_CreateWindow( "SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, w, h, SDL_WINDOW_SHOWN | SDL_WINDOW_FULLSCREEN_DESKTOP  );
    if (window == NULL)
			printf( "Window could not be created! SDL Error: %s\n", SDL_GetError() );
    return window;
}

SDL_Renderer *create_renderer(SDL_Window *window, int scale)
{
  SDL_Renderer *renderer = SDL_CreateRenderer( window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC );
  if( renderer == NULL )
  {
    printf( "Renderer could not be created! SDL Error: %s\n", SDL_GetError() );
  }
  else
  {
    SDL_SetRenderDrawColor( renderer, 0xFF, 0xFF, 0xFF, 0xFF );
    int imgFlags = IMG_INIT_PNG;
    if( !( IMG_Init( imgFlags ) & imgFlags ) )
    {
      printf( "SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError() );
      renderer = NULL;
    }

    //Initialize SDL_ttf
    if( TTF_Init() == -1 )
    {
        return false;    
        printf("SDL_ttf could not initialize\n");
    }

  }
  return renderer;
}
