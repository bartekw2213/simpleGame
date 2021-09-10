#pragma once
#include "Game/Game_Constants.hpp"
#include "Game/Game_Object.hpp"

/**********************************************************************************
    Class that manages an object or a group of similar objects (e.g pipes manager).
    It updates objects' positions and checks for collisions. Based on informations
    retrieved from objects, it informs the game mode if it should end.
***********************************************************************************/
class Game_Objects_Manager {
   public:
    Game_Objects_Manager(Uint8 objects_num);
    ~Game_Objects_Manager();
    void work();

   protected:
    Game_Object** objects;
    Uint8 objects_number;

   private:
    virtual void update_objects_positions() = 0;
};

class Background_Object_Manager : public Game_Objects_Manager {
   public:
    Background_Object_Manager();

   private:
    void update_objects_positions() override;
};

class Header_Object_Manager : public Game_Objects_Manager {
   public:
    Header_Object_Manager();

   private:
    void update_objects_positions() override;
};