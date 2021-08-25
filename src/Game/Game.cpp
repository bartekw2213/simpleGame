#include "Game/Game.hpp"

SDL_Window_Wrapper* Game::window_wrapper = nullptr;
SDL_Renderer_Wrapper* Game::renderer_wrapper = nullptr;
SDL_Texture_Wrapper* Game::texture_wrapper = nullptr;
Game_Mode_Manager* Game::game_mode_manager = nullptr;
SDL_Event Game::event;

void Game::start() {
    SDL_Manager::initialize();

    allocate_private_fields();
    init_private_fields();
    loop();
    delete_private_fields();

    SDL_Manager::quit();
}

void Game::allocate_private_fields() {
    window_wrapper = new SDL_Window_Wrapper();
    renderer_wrapper = new SDL_Renderer_Wrapper();
    texture_wrapper = new SDL_Texture_Wrapper();
    game_mode_manager = new Game_Mode_Manager();
}

void Game::init_private_fields() {
    window_wrapper->initialize_window(GAME_NAME, 400, 700);
    renderer_wrapper->initialize_renderer(window_wrapper->get_renderer());
    texture_wrapper->initialize_texture(TEXTURE_PATH, renderer_wrapper);
}

void Game::delete_private_fields() {
    delete window_wrapper;
    delete renderer_wrapper;
    delete texture_wrapper;
    delete game_mode_manager;
}

void Game::loop() {
    bool quit = false;

    while (!quit) {
        while (SDL_PollEvent(&event) != 0)
            if (event.type == SDL_QUIT) quit = true;

        renderer_wrapper->render_clear();
        game_mode_manager->work();
        renderer_wrapper->render_present();
    }
}