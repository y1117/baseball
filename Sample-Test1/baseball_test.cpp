﻿#include "pch.h"
#include "../240517_baseball/baseball.cpp"
using namespace std;

class BaseballFixture : public testing::Test {
public:
    Baseball game;
    void assertIllegalArgument(string guessNumber) {
        try {
            game.guess(guessNumber);
            FAIL();
        }
        catch (exception e) {
            // PASS
        }
    }

};

TEST_F(BaseballFixture, ThrowExceptionWhenInvalidCase) {
    assertIllegalArgument("12");
    assertIllegalArgument("12s");

}