#pragma once
#include "Game/Game_Constants.hpp"
#include "Game/Game_Objects_Manager.hpp"

/***************************************************************************************
 * Class that represents specific game stage (e.g. main menu, game over menu, gameplay)
 ***************************************************************************************/
class Game_Mode {
   public:
    Game_Mode(GAME_MODE mode_name, int objects_managers_num);
    ~Game_Mode();
    void work();
    const bool mode_ended() { return ended; }

   public:
    const GAME_MODE mode_name;

   protected:
    bool ended;
    int objects_managers_num;
    Game_Objects_Manager** objects_managers;
};