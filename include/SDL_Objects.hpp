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

class SDL_Window_Wrapper {
   public:
    SDL_Window_Wrapper(){};
    ~SDL_Window_Wrapper();
    void initialize_window(const char* title, int x, int y, int width, int height, Uint32 flags = SDL_WINDOW_SHOWN);
    void initialize_window(const char* title, int width, int height, Uint32 flags = SDL_WINDOW_SHOWN);

   private:
    SDL_Window* window = nullptr;
};