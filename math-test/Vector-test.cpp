#include "pch.h"
#include "../math/Vector.h"

TEST(Vector2Test, Init)
{
    Vector2 v0{ 0, 1 };
    EXPECT_FLOAT_EQ(0, v0.x);
    EXPECT_FLOAT_EQ(1, v0.y);
    Vector2 v1 = { 2, 3 };
    EXPECT_FLOAT_EQ(2, v1.x);
    EXPECT_FLOAT_EQ(3, v1.y);
}

TEST(Vector2Test, SubscriptOp)
{
    Vector2 v{1, 2};
    v[0] = 2;
    v[1] = 3;
    EXPECT_FLOAT_EQ(3, v.y);
    EXPECT_FLOAT_EQ(2, v[0]);
}

TEST(Vector2Test, ArithmeticAssignment)
{
    // +=
    Vector2 vPE{ 1.1, 2.1 };
    vPE += Vector2{ 1, 1 };
    EXPECT_FLOAT_EQ(2.1, vPE.x);
    EXPECT_FLOAT_EQ(3.1, vPE.y);
    // -=
    Vector2 vME{ -1, -8.5 };
    vME -= Vector2{ 0, -1 };
    EXPECT_FLOAT_EQ(-1, vME.x);
    EXPECT_FLOAT_EQ(-7.5, vME.y);
    // *=
    Vector2 vTE{ -2.2, 100 };
    vTE *= -4;
    EXPECT_FLOAT_EQ(8.8, vTE.x);
    EXPECT_FLOAT_EQ(-400, vTE.y);
    // /=
    Vector2 vDE{ 450, -1 };
    vDE /= 10;
    EXPECT_FLOAT_EQ(45, vDE.x);
    EXPECT_FLOAT_EQ(-.1, vDE.y);
}
