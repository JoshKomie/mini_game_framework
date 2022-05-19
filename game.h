#pragma once
#include <SDL.h>
#include "input.h"
#include "texture.h"

namespace mgf
{
class Game
{
    public:
        Game();
        int run();
        virtual void create() = 0;
        virtual void update() = 0;
        virtual void render() = 0;
        virtual void close() = 0;
        void set_render_scale(int x, int y);
        Texture *create_texture(std::string path);
    protected:
        void run_frame();
        bool quit;
        SDL_Window *window;
        SDL_Renderer *renderer;
        Input *input;
        /* SDL_DisplayMode display_mode; */
};
}
