#include "Game/Game_Mode_Manager.hpp"

Game_Mode_Manager::Game_Mode_Manager()
    : current_mode_name(GAME_MODE::START_MENU), modes(new Game_Mode*[GAME_MODES_NUM]), current_mode(nullptr) {
    initialize_modes();
}

Game_Mode_Manager::~Game_Mode_Manager() {
    for (int i = 0; i < GAME_MODES_NUM; i++) delete modes[i];
    delete[] modes;
}

void Game_Mode_Manager::work() {
    for (int i = 0; i < GAME_MODES_NUM; i++)
        if (modes[i]->mode_name == current_mode_name) {
            modes[i]->work();
            if (modes[i]->mode_ended()) handle_mode_end();
            break;
        }
}

void Game_Mode_Manager::handle_mode_end() {
    switch (current_mode_name) {
        case GAME_MODE::START_MENU:
            current_mode_name = GAME_MODE::GAME_IN_PROGRESS;
            break;
        case GAME_MODE::GAME_IN_PROGRESS:
            current_mode_name = GAME_MODE::GAME_OVER;
            break;
        case GAME_MODE::GAME_OVER:
            current_mode_name = GAME_MODE::START_MENU;
            break;
        default:
            break;
    }
}

void Game_Mode_Manager::initialize_modes() {
    modes[0] = new Start_Menu_Mode();
    modes[1] = new Game_In_Progress_Mode();
    modes[2] = new Game_Over_Mode();
}