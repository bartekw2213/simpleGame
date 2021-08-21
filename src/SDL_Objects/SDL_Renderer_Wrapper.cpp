#include "SDL_Objects/SDL_Objects.hpp"

SDL_Renderer_Wrapper::~SDL_Renderer_Wrapper() {
    if (renderer != nullptr) SDL_DestroyRenderer(renderer);
}

void SDL_Renderer_Wrapper::initialize_renderer(SDL_Renderer* passed_renderer) {
    if (renderer != nullptr) SDL_DestroyRenderer(renderer);
    renderer = passed_renderer;
}

SDL_Renderer* SDL_Renderer_Wrapper::get_renderer() { return renderer; }