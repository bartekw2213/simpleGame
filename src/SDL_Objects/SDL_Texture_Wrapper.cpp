#include "SDL_Objects/SDL_Objects.hpp"

SDL_Texture_Wrapper::SDL_Texture_Wrapper() : texture(nullptr), renderer_wrapper(nullptr) {}

SDL_Texture_Wrapper::~SDL_Texture_Wrapper() { free(); }

void SDL_Texture_Wrapper::initialize_texture(const std::string& path, SDL_Renderer_Wrapper* renderer_wrapper) {
    this->renderer_wrapper = renderer_wrapper;
    load_texture(path);
}

void SDL_Texture_Wrapper::load_texture(const std::string& path) {
    SDL_Surface* loadedSurface = IMG_Load(path.c_str());

    if (loadedSurface == NULL) SDL_Manager::throw_IMG_error();

    texture = SDL_CreateTextureFromSurface(renderer_wrapper->get_renderer(), loadedSurface);
    if (texture == NULL) SDL_Manager::throw_SDL_error();

    SDL_FreeSurface(loadedSurface);
}

void SDL_Texture_Wrapper::render(const int x, const int y, SDL_Rect* clip) {
    SDL_Rect renderQuad = {x, y, clip->w * TEXTURE_MULTIPLIER, clip->h * TEXTURE_MULTIPLIER};
    SDL_RenderCopy(renderer_wrapper->get_renderer(), texture, clip, &renderQuad);
}

void SDL_Texture_Wrapper::render_fullscreen(SDL_Rect* clip) {
    SDL_RenderCopy(renderer_wrapper->get_renderer(), texture, clip, nullptr);
}

void SDL_Texture_Wrapper::free() {
    if (texture != nullptr) {
        SDL_DestroyTexture(texture);
        texture = nullptr;
    }
}