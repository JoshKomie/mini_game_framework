#include "input.h"

void mgf::Input::clear_keys()
{
  for (int i = 0; i < EVENT_LENGTH; i++)
  {
    keys[i] = SDL_SCANCODE_UNKNOWN;
  }

}
void mgf::Input::add_key(SDL_Scancode e)
{

  for (int i = 0; i < EVENT_LENGTH; i++)
  {
    if (keys[i] == SDL_SCANCODE_UNKNOWN)
    {
      keys[i] = e;
      return;
    }
  }
}

bool mgf::Input::key_pressed(SDL_Scancode key)
{
  for (int i = 0; i < EVENT_LENGTH; i++)
  {
    if (keys[i] != SDL_SCANCODE_UNKNOWN && keys[i] == key)
      return true;
  }
  return false;
}

bool mgf::Input::any_key_pressed()
{
  for (int i = 0; i < EVENT_LENGTH; i++)
  {
    if (keys[i] != SDL_SCANCODE_UNKNOWN)
      return true;
  }
  return false;
}

SDL_Scancode* mgf::Input::all_keys_pressed()
{
    return keys;
}
