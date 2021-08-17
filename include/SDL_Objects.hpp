#pragma once
#include <SDL2/SDL.h>

#include <stdexcept>

class SDL_Manager {
   public:
    static void initialize() {
        if (SDL_Init(SDL_INIT_VIDEO) != 0) SDL_Manager::throw_SDL_error();
    };
    static void quit() { SDL_Quit(); };
    static void throw_SDL_error() { throw std::runtime_error(SDL_GetError()); }
};

class SDL_Window_Wrapper {
   public:
    SDL_Window_Wrapper(){};
    ~SDL_Window_Wrapper();
    void initialize_window(const char* title, int x, int y, int width, int height, Uint32 flags = SDL_WINDOW_SHOWN);
    void initialize_window(const char* title, int width, int height, Uint32 flags = SDL_WINDOW_SHOWN);

   private:
    SDL_Window* window = nullptr;
};