#pragma once
#include "Game/Game_Mode.hpp"

/********************************************************************************
 * Class that handles all possible game modes / stages and switches between them
 ********************************************************************************/
class Game_Mode_Manager {
   public:
    Game_Mode_Manager();
    ~Game_Mode_Manager();
    void work();

   private:
    void initialize_modes();
    void handle_mode_end();

   private:
    GAME_MODE current_mode_name;
    Game_Mode** modes;
    Game_Mode* current_mode;
};