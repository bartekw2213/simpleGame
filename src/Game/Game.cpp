#include "Game_Objects.hpp"

Game::Game() { SDL_Manager::initialize(); }

Game::~Game() { SDL_Manager::quit(); }

void Game::start() {
    window_wrapper.initialize_window(GAME_NAME, 400, 700);
    renderer_wrapper.initialize_renderer(window_wrapper.get_renderer());
    texture_wrapper.initialize_texture(TEXTURE_PATH, &renderer_wrapper);
    loop();
}

void Game::loop() {
    bool quit = false;

    while (!quit) {
        while (SDL_PollEvent(&event) != 0)
            if (event.type == SDL_QUIT) quit = true;
    }
}