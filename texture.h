#pragma once
#include <SDL.h>
#include <string>
namespace mgf
{
    class Texture
    {
        public:
            Texture(SDL_Renderer* renderer, std::string path);
            ~Texture();
            void render(int x, int y);
            void set_src(int x, int y, int w, int h);
            /* bool loadFromFile( std::string path ); */
            /* void free(); */
            /* //Set color modulation */
            /* void setColor( Uint8 red, Uint8 green, Uint8 blue ); */

            /* //Set blending */
            /* void setBlendMode( SDL_BlendMode blending ); */

            /* //Set alpha modulation */
            /* void setAlpha( Uint8 alpha ); */

        protected:
            SDL_Renderer* renderer;
            SDL_Texture* sdl_texture;
            std::string path;
            SDL_Rect src, dest;
            int width;
            int height;
    };
}
