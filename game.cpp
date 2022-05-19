#include "game.h"
#include "sdl_helper.h"


mgf::Game::Game():
    quit(false),
    window(nullptr),
    renderer(nullptr),
    input(new mgf::Input())
{

}

int mgf::Game::run()
{
    if (!init_sdl())
        return 1;
    window = create_window(800, 600);
    if (!window)
        return 1;
    renderer = create_renderer(window, 1);
    if (!renderer)
        return 1;

    create();
    while( !quit )
    {
        run_frame();
    }
    close();

}



void mgf::Game::run_frame()
{

    //get input
    SDL_Event e;
    input->clear_keys();
    while( SDL_PollEvent( &e ) != 0 )
    {
        if( e.type == SDL_QUIT )
        {
            quit = true;
        }
        else if (e.type == SDL_KEYDOWN)
        {
            if (e.key.keysym.scancode == SDL_SCANCODE_ESCAPE)
                quit = true;
            else
                input->add_key(e.key.keysym.scancode);
        }
    }

    //update
    update();

    //render
    SDL_SetRenderDrawColor( renderer, 3, 15, 36, 255 );
    SDL_RenderClear( renderer );
    render();
    SDL_RenderPresent( renderer );
}

void mgf::Game::set_render_scale(int x, int y)
{
    SDL_RenderSetScale(renderer, x, y);
}

mgf::Texture *mgf::Game::create_texture(std::string path)
{
    return new Texture(renderer, path);
}
