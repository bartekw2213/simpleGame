#pragma once

/************************
 * General game constans
 ************************/
#define GAME_NAME "Flappy Bird"
#define GAME_WIDTH 400
#define GAME_HEIGHT 700
#define TEXTURE_PATH "../../resources/sprites/main-sprite.png"
#define TEXTURE_MULTIPLIER 2  // How many times each texture will be bigger than original one

/*********************************
 * Constants regarding game modes
 *********************************/
#define START_MENU_OBJECTS_MANAGER_NUM 1
#define GAME_IN_PROGRESS_OBJECTS_MANAGER_NUM 0
#define GAME_OVER_OBJECTS_MANAGER_NUM 0

#define GAME_MODES_NUM 3

/**********************************************
 * Enum class representing possible game modes
 **********************************************/
enum class GAME_MODE { START_MENU, GAME_IN_PROGRESS, GAME_OVER };

/************************************************
 * Number of objects each object manager manages
 ************************************************/
#define BACKGROUND_OBJECT_MANAGER_OBJECTS_NUM 1

/*****************************************************
 * Source coordinates from the texture of each object
 *****************************************************/
namespace src_texture {
const int BG_X = 0;
const int BG_Y = 0;
const int BG_W = 140;
const int BG_H = 255;
const int BG_START_X = 0;
const int BG_START_Y = 0;
}