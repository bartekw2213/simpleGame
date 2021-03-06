#include "SDL_Objects/SDL_Objects.hpp"

void SDL_Manager::initialize() {
    if (SDL_Init(SDL_INIT_VIDEO) != 0) SDL_Manager::throw_SDL_error();

    int imgFlags = IMG_INIT_PNG;
    if (!(IMG_Init(imgFlags) & imgFlags)) SDL_Manager::throw_IMG_error();

    if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1")) printf("Warning! Linear texture filtering not enabled!\n");
}

void SDL_Manager::quit() { SDL_Quit(); };

void SDL_Manager::throw_SDL_error() { throw std::runtime_error(SDL_GetError()); }

void SDL_Manager::throw_IMG_error() { throw std::runtime_error(IMG_GetError()); }
