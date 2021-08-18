#pragma once
#include <SDL2/SDL.h>

// *************************************************************************
// Class responsible for calculating which sprite of animation should be
// shown right now.
// For example animation:
//      * lasts 2 sec
//      * consists o 10 sprites
// It's 0.25 sec since animation started, what sprite should be shown now?
// Instace of this class gives you an answer
// *************************************************************************
class AnimationSpriteTimer {
   public:
    AnimationSpriteTimer(Uint32 anim_time, Uint16 sprts_num);
    void start_countdown();
    const Uint16 index_of_sprite_displayed_now();
    const bool countdown_finished();

   private:
    bool started;
    Uint32 start_time;
    const Uint32 animation_time;
    const Uint32 time_per_sprite;
    const Uint16 sprites_num;
};