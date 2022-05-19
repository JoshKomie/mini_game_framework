#pragma once
#include <SDL.h>

bool init_sdl();
SDL_Window *create_window(int w, int h);
SDL_Renderer *create_renderer(SDL_Window *window, int scale);
