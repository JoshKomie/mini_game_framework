#include "texture.h"
#include <SDL.h>
#include <SDL_image.h>

mgf::Texture::Texture(SDL_Renderer* renderer, std::string path): renderer(renderer), path(path)
{
  sdl_texture = IMG_LoadTexture(renderer, path.c_str());
  SDL_QueryTexture(sdl_texture, NULL, NULL, &width, &height);
  src = {0, 0, width, height};
}

mgf::Texture::~Texture()
{
	if( sdl_texture != NULL )
	{
		SDL_DestroyTexture( sdl_texture );
    sdl_texture = NULL;//mTexture = NULL;
		width = height = 0;
	}
}

void mgf::Texture::set_src(int x, int y, int w, int h)
{
  src.x = x;
  src.y = y;
  src.w = w;
  src.h = h;
  width = w;
  height = h;
}
void mgf::Texture::render( int x, int y)
{
  dest = {x, y, width, height};
	SDL_RenderCopy(renderer, sdl_texture, &src, &dest);
}

/* bool mgf::Texture::loadFromFile( std::string path ) */
/* { */
/* 	free(); */
/* 	SDL_Texture* newTexture = NULL; */
/* 	SDL_Surface* loadedSurface = IMG_Load( path.c_str() ); */
/* 	if( loadedSurface == NULL ) */
/* 	{ */
/* 		printf( "Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError() ); */
/* 	} */
/* 	else */
/* 	{ */
/* 		/1* SDL_SetColorKey( loadedSurface, SDL_TRUE, SDL_MapRGB( loadedSurface->format, 0, 0xFF, 0xFF ) ); *1/ */
/*     newTexture = SDL_CreateTextureFromSurface( renderer, loadedSurface ); */
/* 		if( newTexture == NULL ) */
/* 		{ */
/* 			printf( "Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError() ); */
/* 		} */
/* 		else */
/* 		{ */
/* 			mWidth = loadedSurface->w; */
/* 			mHeight = loadedSurface->h; */
/* 		} */
/* 		SDL_FreeSurface( loadedSurface ); */
/* 	} */
/* 	mTexture = newTexture; */
/*   SDL_SetTextureBlendMode(mTexture, SDL_BLENDMODE_BLEND); */
/* 	return mTexture != NULL; */
/* } */

/* void mgf::Texture::free() */
/* { */
/* 	if( mTexture != NULL ) */
/* 	{ */
/* 		SDL_DestroyTexture( mTexture ); */
/* 		mTexture = NULL; */
/* 		mWidth = 0; */
/* 		mHeight = 0; */
/* 	} */
/* } */

/* void Texture::setColor( Uint8 red, Uint8 green, Uint8 blue ) */
/* { */
/* 	//Modulate texture rgb */
/* 	SDL_SetTextureColorMod( mTexture, red, green, blue ); */
/* } */

/* void Texture::setBlendMode( SDL_BlendMode blending ) */
/* { */
/* 	//Set blending function */
/* 	SDL_SetTextureBlendMode( mTexture, blending ); */
/* } */
		
/* void Texture::setAlpha( Uint8 alpha ) */
/* { */
/* 	//Modulate texture alpha */
/* 	SDL_SetTextureAlphaMod( mTexture, alpha ); */
/* } */


/* int mgf::Texture::getWidth() */
/* { */
/* 	return mWidth; */
/* } */

/* int mgf::Texture::getHeight() */
/* { */
/* 	return mHeight; */
/* } */
