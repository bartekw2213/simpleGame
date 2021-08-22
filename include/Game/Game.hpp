#pragma once
#include "SDL_Objects/SDL_Objects.hpp"

#define GAME_NAME "Flappy Bird"
#define GAME_WIDTH 400
#define GAME_HEIGHT 700
#define TEXTURE_PATH "../resources/sprites/main-sprite.png"

class Game {
   public:
    static void start();

   private:
    static void loop();
    static void allocate_private_fields();
    static void init_private_fields();
    static void delete_private_fields();

   private:
    static SDL_Window_Wrapper* window_wrapper;
    static SDL_Renderer_Wrapper* renderer_wrapper;
    static SDL_Texture_Wrapper* texture_wrapper;
    static SDL_Event event;
};