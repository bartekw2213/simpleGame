#include "Game/Game_Objects_Manager.hpp"

Game_Objects_Manager::Game_Objects_Manager(Uint8 objects_num)
    : objects(new Game_Object*[objects_num]), objects_number(objects_num) {}

Game_Objects_Manager::~Game_Objects_Manager() {
    for (int i = 0; i < objects_number; i++) delete objects[i];
    delete[] objects;
}

void Game_Objects_Manager::work() {
    update_objects_positions();
    for (int i = 0; i < objects_number; i++) objects[i]->render();
}

Background_Object_Manager::Background_Object_Manager() : Game_Objects_Manager(BACKGROUND_OBJECT_MANAGER_OBJECTS_NUM) {
    objects[0] = new Background_Object();
}

void Background_Object_Manager::update_objects_positions() {}

Header_Object_Manager::Header_Object_Manager() : Game_Objects_Manager(HEADER_OBJECT_MANAGER_OBJECTS_NUM) {
    objects[0] = new Header_Object();
}

void Header_Object_Manager::update_objects_positions() {}