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

TEST(Vector2Test, Assignment)
{
    Vector2 v{ 1, 5 };
    v = Vector2{ 10, -1 };
    EXPECT_FLOAT_EQ(10, v.x);
    EXPECT_FLOAT_EQ(-1, v.y);
}

TEST(Vector2Test, UnaryNegation)
{
    Vector2 v{-1, 2};
    EXPECT_FLOAT_EQ(1, (-v).x);
    EXPECT_FLOAT_EQ(-2, (-v).y);
    // v hasn't changed
    EXPECT_FLOAT_EQ(-1, v.x);
    EXPECT_FLOAT_EQ(2, v.y);
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

TEST(Vector2Test, ArithmeticOperators)
{
    // +
    Vector2 vP0{ 1, 1 }, vP1{ 1, -2 };
    Vector2 vPR = vP0 + vP1;
    EXPECT_FLOAT_EQ(2, vPR.x);
    EXPECT_FLOAT_EQ(-1, vPR.y);
    // vP1 didn't change
    EXPECT_FLOAT_EQ(1, vP1.x);
    EXPECT_FLOAT_EQ(-2, vP1.y);
    // vP0 didn't change
    EXPECT_FLOAT_EQ(1, vP0.x);
    EXPECT_FLOAT_EQ(1, vP0.y);

    // -
    Vector2 vM0{ 1, 1 }, vM1{ 1, -2 };
    Vector2 vMR = vP0 - vP1;
    EXPECT_FLOAT_EQ(0, vMR.x);
    EXPECT_FLOAT_EQ(3, vMR.y);
    // vM1 didn't change
    EXPECT_FLOAT_EQ(1, vM1.x);
    EXPECT_FLOAT_EQ(-2, vM1.y);
    // vM0 didn't change
    EXPECT_FLOAT_EQ(1, vM0.x);
    EXPECT_FLOAT_EQ(1, vM0.y);

    // *
    Vector2 vT0{ -2, 8 };
    Vector2 vTR = vT0 * 2;
    EXPECT_FLOAT_EQ(-4, vTR.x);
    EXPECT_FLOAT_EQ(16, vTR.y);
    // vT0 didn't change
    EXPECT_FLOAT_EQ(-2, vT0.x);
    EXPECT_FLOAT_EQ(8, vT0.y);
    // change the order of the operation
    vTR = 3 * vT0;
    EXPECT_FLOAT_EQ(-6, vTR.x);
    EXPECT_FLOAT_EQ(24, vTR.y);
    // vT0 didn't change
    EXPECT_FLOAT_EQ(-2, vT0.x);
    EXPECT_FLOAT_EQ(8, vT0.y);

    // /
    Vector2 vD0{ 3, 10 };
    Vector2 vDR = vD0 / 2 ;
    EXPECT_FLOAT_EQ(1.5, vDR.x);
    EXPECT_FLOAT_EQ(5, vDR.y);
    // vD0 didn't change
    EXPECT_FLOAT_EQ(3, vD0.x);
    EXPECT_FLOAT_EQ(10, vD0.y);
}
