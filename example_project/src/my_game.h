#pragma once
#include <mgf.h>

class MyGame : public mgf::Game
{
    public:
        void create();
        void update();
        void render();
        void close();

    private:
        mgf::Texture *tex;
        int x, y;
};
