#pragma once
#include <SDL2/SDL.h>

#include <stdexcept>

class SDL_Manager {
   public:
    static void initialize();
    static void quit();
    static void throw_SDL_error();
};

class SDL_Window_Wrapper {
   public:
    SDL_Window_Wrapper(){};
    ~SDL_Window_Wrapper();
    void initialize_window(const char* title, int x, int y, int width, int height, Uint32 flags = SDL_WINDOW_SHOWN);
    void initialize_window(const char* title, int width, int height, Uint32 flags = SDL_WINDOW_SHOWN);
    const SDL_Renderer* get_renderer();

   private:
    SDL_Window* window = nullptr;
};

class SDL_Renderer_Wrapper {
   public:
    SDL_Renderer_Wrapper(){};
    ~SDL_Renderer_Wrapper();
    void initialize_renderer(SDL_Renderer*& passed_renderer);

   private:
    SDL_Renderer* renderer = nullptr;
};