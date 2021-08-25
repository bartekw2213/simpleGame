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

class Start_Menu_Mode : public Game_Mode {
   public:
    Start_Menu_Mode();
};

class Game_In_Progress_Mode : public Game_Mode {
   public:
    Game_In_Progress_Mode();
};

class Game_Over_Mode : public Game_Mode {
   public:
    Game_Over_Mode();
};
