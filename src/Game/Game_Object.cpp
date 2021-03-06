#include "Game/Game_Object.hpp"

#include "Game/Game.hpp"

using namespace src_texture;

Game_Object::Game_Object(int startX, int startY, int srcRecX, int srcRecY, int srcRecW, int srcRecH)
    : xPos(startX),
      yPos(startY),
      width(srcRecW * TEXTURE_MULTIPLIER),
      height(srcRecH * TEXTURE_MULTIPLIER),
      texture_wrapper(Game::get_texture_wrapper()) {
    srcRec.x = srcRecX;
    srcRec.y = srcRecY;
    srcRec.w = srcRecW;
    srcRec.h = srcRecH;
}

void Game_Object::render() { texture_wrapper->render(xPos, yPos, &srcRec); }

void Game_Object::update_position(int newX, int newY) {
    xPos = newX;
    yPos = newY;
}

Background_Object::Background_Object() : Game_Object(BG_START_X, BG_START_Y, BG_X, BG_Y, BG_W, BG_H) {}

void Background_Object::render() { texture_wrapper->render_fullscreen(&srcRec); }

Header_Object::Header_Object() : Game_Object(HEADER_START_X, HEADER_START_Y, HEADER_X, HEADER_Y, HEADER_W, HEADER_H) {}