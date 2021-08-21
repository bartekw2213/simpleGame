#pragma once
#include "SDL_Objects/SDL_Objects.hpp"

#define GAME_NAME "Flappy Bird"
#define GAME_WIDTH 400
#define GAME_HEIGHT 700
#define TEXTURE_PATH "../resources/sprites/main-sprite.png"

class Game {
   public:
    Game();
    ~Game();
    void start();

   private:
    void loop();

   private:
    SDL_Window_Wrapper window_wrapper;
    SDL_Renderer_Wrapper renderer_wrapper;
    SDL_Texture_Wrapper texture_wrapper;
    SDL_Event event;
};