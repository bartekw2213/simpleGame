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