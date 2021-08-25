#pragma once
#include "Game/Game_Constants.hpp"
#include "SDL_Objects/SDL_Objects.hpp"

class Game {
   public:
    static void start();
    static inline SDL_Texture_Wrapper* get_texture_wrapper();

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