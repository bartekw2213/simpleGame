#pragma once

/************************
 * General game constans
 ************************/
#define GAME_NAME "Flappy Bird"
#define GAME_WIDTH 400
#define GAME_HEIGHT 700
#define TEXTURE_PATH "../../resources/sprites/main-sprite.png"

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
