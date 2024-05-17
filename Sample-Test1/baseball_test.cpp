#include "pch.h"
#include "../240517_baseball/baseball.cpp"
using namespace std;

TEST(BaseballGame, ThrowExceptionWhenInputLengthIsUnmached) {
    Baseball game;

    EXPECT_THROW(game.guess(string("12")), length_error);
}