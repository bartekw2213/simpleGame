#pragma once
#include <SDL2/SDL.h>

#include <stdexcept>

class SDL_Manager {
   public:
    static void initialize() {
        if (SDL_Init(SDL_INIT_VIDEO) != 0) throw std::runtime_error(SDL_GetError());
    };
    static void quit() { SDL_Quit(); };
};