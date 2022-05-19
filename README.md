# Mini Game Framework

A tiny (but growing) collection of helper/wrapper classes for sdl2. I started this project to jumpstart my many experiments which use sdl2. It is good for getting something up on screen quickly, see example below:

`
#include "my_game.h"

void MyGame::create()
{
    x = y = 0;
    tex = create_texture("knight.png");
}

void MyGame::update()
{
    int speed =10;
    if (input->key_pressed(SDL_SCANCODE_A))
        x -= speed;
    else if (input->key_pressed(SDL_SCANCODE_D))
        x += speed;

    if (input->key_pressed(SDL_SCANCODE_W))
        y -= speed;
    else if (input->key_pressed(SDL_SCANCODE_S))
        y += speed;
}

void MyGame::render()
{
    tex->render(x, y);
}

void MyGame::close()
{
    std::cout << "close" << end;
}
`


