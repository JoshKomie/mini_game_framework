#include "my_game.h"

void MyGame::create()
{
    x = y = 0;
    tex = create_texture("assets/knight.png");
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
}
