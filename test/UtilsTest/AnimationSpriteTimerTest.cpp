#include <gtest/gtest.h>

#include "SDL_Objects/SDL_Objects.hpp"
#include "Utils/Utils.hpp"

class AnimationSpriteTimerTest : public ::testing::Test {
   protected:
    AnimationSpriteTimerTest() : timer(2000, 10) { SDL_Manager::initialize(); }
    ~AnimationSpriteTimerTest() { SDL_Manager::quit(); }

    Animation_Sprite_Timer timer;
};

TEST_F(AnimationSpriteTimerTest, Test1) {
    Uint32 startTime = SDL_GetTicks();
    timer.start_countdown();

    EXPECT_EQ(0, timer.index_of_sprite_displayed_now());

    while (SDL_GetTicks() - startTime < 200)
        ;

    EXPECT_EQ(1, timer.index_of_sprite_displayed_now());

    while (SDL_GetTicks() - startTime < 600)
        ;

    EXPECT_EQ(3, timer.index_of_sprite_displayed_now());

    while (SDL_GetTicks() - startTime < 1800)
        ;

    EXPECT_EQ(9, timer.index_of_sprite_displayed_now());
}