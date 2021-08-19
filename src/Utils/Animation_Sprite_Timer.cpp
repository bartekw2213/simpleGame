#include "Utils.hpp"

Animation_Sprite_Timer::Animation_Sprite_Timer(Uint32 anim_time, Uint16 sprts_num)
    : started(false),
      start_time(0),
      animation_time(anim_time),
      sprites_num(sprts_num),
      time_per_sprite(anim_time / sprts_num) {}

void Animation_Sprite_Timer::start_countdown() {
    started = true;
    start_time = SDL_GetTicks();
}

const Uint16 Animation_Sprite_Timer::index_of_sprite_displayed_now() {
    if (!started) return 0;
    return (SDL_GetTicks() - start_time) / time_per_sprite;
}

const bool Animation_Sprite_Timer::countdown_finished() {
    if (!started) return true;

    if ((SDL_GetTicks() - start_time) > animation_time) {
        started = false;
        return true;
    } else
        return false;
}