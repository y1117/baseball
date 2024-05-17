﻿#include "pch.h"
#include "../240517_baseball/baseball.cpp"
using namespace std;

class BaseballFixture : public testing::Test {
public:
    Baseball game{ "123" };
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
    assertIllegalArgument("121");
}
TEST_F(BaseballFixture, ReturnSolvedResultIfMatchedNumber) {
    GuessResult result = game.guess("123");

    EXPECT_TRUE(result.sovled);
    EXPECT_EQ(3, result.strikes);
    EXPECT_EQ(0, result.balls);
}
TEST_F(BaseballFixture, ReturnSolvedResult2Strikes0Ball) {
    GuessResult result = game.guess("124");

    EXPECT_FALSE(result.sovled);
    EXPECT_EQ(2, result.strikes);
    EXPECT_EQ(0, result.balls);
}
TEST_F(BaseballFixture, ReturnSolvedResult1Strikes2Ball) {
    GuessResult result = game.guess("132");

    EXPECT_FALSE(result.sovled);
    EXPECT_EQ(1, result.strikes);
    EXPECT_EQ(2, result.balls);
}
