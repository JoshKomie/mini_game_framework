#pragma once
#include <SDL.h> 
const int EVENT_LENGTH = 16;

namespace mgf
{
  class Input
  {
    public:
      void clear_keys();
      void add_key(SDL_Scancode code);
      bool key_pressed(SDL_Scancode key);
      bool any_key_pressed();
      SDL_Scancode* all_keys_pressed();
    private:
      SDL_Scancode keys[EVENT_LENGTH];
  };
};
