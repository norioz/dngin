#include "pch.h"
#include "../math/Vector3.h"

void expectVector3Values (float x, float y, float z, Vector3 & v) {
    EXPECT_FLOAT_EQ(x, v.x);
    EXPECT_FLOAT_EQ(y, v.y);
    EXPECT_FLOAT_EQ(z, v.z);
}

TEST(Vector3Test, Init)
{
    Vector3 v0{ 0, 1, -1 };
    expectVector3Values(0, 1, -1, v0);
    Vector3 v1 = { 2, 3, 1 };
    expectVector3Values(2, 3, 1, v1);
}

TEST(Vector3Test, Equality)
{
    Vector3 v0{ 1, 2, 3 }, v1{ -1, -1, -1 }, v2{ -1, -1, -1 };
    EXPECT_TRUE(v0 != v1);
    EXPECT_FALSE(v0 == v1);
    EXPECT_FALSE(v1 != v2);
    EXPECT_TRUE(v1 == v2);
}

TEST(Vector3Test, SubscriptOp)
{
    Vector3 v{ 1, 2, -1 };
    v[0] = 2;
    v[1] = 3;
    v[2] = 4.1;
    EXPECT_FLOAT_EQ(3, v.y);
    EXPECT_FLOAT_EQ(2, v[0]);
    EXPECT_FLOAT_EQ(4.1, v.z);
}

TEST(Vector3Test, Assignment)
{
    Vector3 v{ 1, 5, 1};
    v = Vector3{ 10, -1 , 5 };
    expectVector3Values(10, -1, 5, v);
}

TEST(Vector3Test, UnaryNegation)
{
    Vector3 v{ -1, 2, -1.1 };
    expectVector3Values(1, -2, 1.1, -v);
    // v hasn't changed
    expectVector3Values(-1, 2, -1.1, v);
}

TEST(Vector3Test, ArithmeticAssignment)
{
    // +=
    Vector3 vPE{ 1.1, 2.1, 3.1 };
    vPE += Vector3{ 1, 1, 1 };
    expectVector3Values(2.1, 3.1, 4.1, vPE);
    // -=
    Vector3 vME{ -1, -8.5, -12.12 };
    vME -= Vector3{ 0, -1, 1 };
    expectVector3Values(-1, -7.5, -13.12, vME);
    // *=
    Vector3 vTE{ -2.2, 100, 0 };
    vTE *= -4;
    expectVector3Values(8.8, -400, 0, vTE);
    // /=
    Vector3 vDE{ 450, -1, 1.1 };
    vDE /= 10;
    expectVector3Values(45, -0.1, 0.11, vDE);
}

TEST(Vector3Test, ArithmeticOperators)
{
    // +
    Vector3 vP0{ 1, 1, -1 }, vP1{ 1, -2, 12.12 };
    Vector3 vPR = vP0 + vP1;
    expectVector3Values(2, -1, 11.12, vPR);
    // vP1 didn't change
    expectVector3Values(1, -2, 12.12, vP1);
    // vP0 didn't change
    expectVector3Values(1, 1, -1, vP0);
    // -
    Vector3 vM0{ 1, 1, -1 }, vM1{ 1, -2, 8.8 };
    Vector3 vMR = vM0 - vM1;
    expectVector3Values(0, 3, -9.8, vMR);
    // vM1 didn't change
    expectVector3Values(1, -2, 8.8, vM1);
    // vM0 didn't change
    expectVector3Values(1, 1, -1, vM0);
    // *
    Vector3 vT0{ -2, 8, 0 };
    Vector3 vTR = vT0 * 2;
    expectVector3Values(-4, 16, 0, vTR);
    // vT0 didn't change
    expectVector3Values(-2, 8, 0, vT0);
    // change the order of the operation
    vTR = 3 * vT0;
    expectVector3Values(-6, 24, 0, vTR);
    // vT0 didn't change
    expectVector3Values(-2, 8, 0, vT0);
    // /
    Vector3 vD0{ 3, 10, -12 };
    Vector3 vDR = vD0 / 2;
    expectVector3Values(1.5, 5, -6, vDR);
    // vD0 didn't change
    expectVector3Values(3, 10, -12, vD0);
}
