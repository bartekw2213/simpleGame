#include "Game/Game_Mode.hpp"

#include "Game/Game_Objects_Manager.hpp"

Game_Mode::Game_Mode(GAME_MODE mode_name, int obj_mng_num)
    : mode_name(mode_name),
      ended(true),
      objects_managers_num(obj_mng_num),
      objects_managers(new Game_Objects_Manager*[obj_mng_num]) {}

Game_Mode::~Game_Mode() {
    for (int i = 0; i < objects_managers_num; i++) delete objects_managers[i];
    delete[] objects_managers;
}

void Game_Mode::work() {
    ended = false;
    for (int i = 0; i < objects_managers_num; i++) objects_managers[i]->work();
}

Start_Menu_Mode::Start_Menu_Mode() : Game_Mode(GAME_MODE::START_MENU, START_MENU_OBJECTS_MANAGER_NUM) {
    objects_managers[0] = new Background_Object_Manager();
};

Game_In_Progress_Mode::Game_In_Progress_Mode()
    : Game_Mode(GAME_MODE::GAME_IN_PROGRESS, GAME_IN_PROGRESS_OBJECTS_MANAGER_NUM){};

Game_Over_Mode::Game_Over_Mode() : Game_Mode(GAME_MODE::GAME_OVER, GAME_OVER_OBJECTS_MANAGER_NUM){};
