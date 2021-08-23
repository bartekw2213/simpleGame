#pragma once
#include "SDL_Objects/SDL_Objects.hpp"

/**************************************************************************
    Class that represents single game object (e.g. Background, Bird, Pipe)
    Game_Object_Manager manages this object by updating it's position and
    checking if it collided with something else.
***************************************************************************/
class Game_Object {
   public:
    Game_Object(int startX, int startY, int srcRecX, int srcRecY, int srcRecW, int srcRecH);
    virtual void render();
    void update_position(int newX, int newY);
    const Uint16 getX() { return xPos; }
    const Uint16 getY() { return yPos; }
    const Uint16 getW() { return width; }
    const Uint16 getH() { return height; }

   protected:
    Uint16 xPos;
    Uint16 yPos;
    SDL_Rect srcRec;
    const Uint16 width;
    const Uint16 height;
    SDL_Texture_Wrapper* texture_wrapper;
};