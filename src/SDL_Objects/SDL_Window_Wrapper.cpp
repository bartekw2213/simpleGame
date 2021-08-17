#include "SDL_Objects.hpp"

SDL_Window_Wrapper::~SDL_Window_Wrapper() {
    if (window != nullptr) SDL_DestroyWindow(window);
}

void SDL_Window_Wrapper::initialize_window(const char* title, int width, int height, Uint32 flags) {
    initialize_window(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, flags);
}

void SDL_Window_Wrapper::initialize_window(const char* title, int x, int y, int width, int height, Uint32 flags) {
    window = SDL_CreateWindow(title, x, y, width, height, flags);
    if (window == NULL) throw std::runtime_error(SDL_GetError());
}