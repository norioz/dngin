#include "pch.h"
#include "../math/Vector2.h"

void expectVector2Values (float x, float y, Vector2 & v) {
    EXPECT_FLOAT_EQ(x, v.x);
    EXPECT_FLOAT_EQ(y, v.y);
}

TEST(Vector2Test, Init)
{
    Vector2 v0{ 0, 1 };
    expectVector2Values(0, 1, v0);
    Vector2 v1 = { 2, 3 };
    expectVector2Values(2, 3, v1);
}

TEST(Vector2Test, Equality)
{
    Vector2 v0{ 1, 2 }, v1{ -1, -1 }, v2{ -1, -1 };
    EXPECT_TRUE(v0 != v1);
    EXPECT_FALSE(v0 == v1);
    EXPECT_FALSE(v1 != v2);
    EXPECT_TRUE(v1 == v2);
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
    expectVector2Values(10, -1, v);
}

TEST(Vector2Test, UnaryNegation)
{
    Vector2 v{-1, 2};
    expectVector2Values(1, -2, -v);
    // v hasn't changed
    expectVector2Values(-1, 2, v);
}

TEST(Vector2Test, ArithmeticAssignment)
{
    // +=
    Vector2 vPE{ 1.1, 2.1 };
    vPE += Vector2{ 1, 1 };
    expectVector2Values(2.1, 3.1, vPE);
    // -=
    Vector2 vME{ -1, -8.5 };
    vME -= Vector2{ 0, -1 };
    expectVector2Values(-1, -7.5, vME);
    // *=
    Vector2 vTE{ -2.2, 100 };
    vTE *= -4;
    expectVector2Values(8.8, -400, vTE);
    // /=
    Vector2 vDE{ 450, -1 };
    vDE /= 10;
    expectVector2Values(45, -0.1, vDE);
}

TEST(Vector2Test, ArithmeticOperators)
{
    // +
    Vector2 vP0{ 1, 1 }, vP1{ 1, -2 };
    Vector2 vPR = vP0 + vP1;
    expectVector2Values(2, -1, vPR);
    // vP1 didn't change
    expectVector2Values(1, -2, vP1);
    // vP0 didn't change
    expectVector2Values(1, 1, vP0);
    // -
    Vector2 vM0{ 1, 1 }, vM1{ 1, -2 };
    Vector2 vMR = vM0 - vM1;
    expectVector2Values(0, 3, vMR);
    // vM1 didn't change
    expectVector2Values(1, -2, vM1);
    // vM0 didn't change
    expectVector2Values(1, 1, vM0);
    // *
    Vector2 vT0{ -2, 8 };
    Vector2 vTR = vT0 * 2;
    expectVector2Values(-4, 16, vTR);
    // vT0 didn't change
    expectVector2Values(-2, 8, vT0);
    // change the order of the operation
    vTR = 3 * vT0;
    expectVector2Values(-6, 24, vTR);
    // vT0 didn't change
    expectVector2Values(-2, 8, vT0);
    // /
    Vector2 vD0{ 3, 10 };
    Vector2 vDR = vD0 / 2 ;
    expectVector2Values(1.5, 5, vDR);
    // vD0 didn't change
    expectVector2Values(3, 10, vD0);
}

TEST(Vector2Test, Magnitude)
{
    EXPECT_FLOAT_EQ(3.605551275463989, magnitude(Vector2{2, 3}));
    EXPECT_FLOAT_EQ(5, magnitude(Vector2{-4, 3}));
}

TEST(Vector2Test, Normalize)
{
    Vector2 v{ 1, 1 };
    Vector2 norm = normalize(v);
    expectVector2Values(0.707107, 0.707107, norm);
    // a unit vector should normalize to itself
    v.x = 0.707107; v.y = 0.707107;
    norm = normalize(v);
    expectVector2Values(0.707107, 0.707107, norm);
    // unit vector points in the direction of the original
    v.x = -1; v.y = -1;
    norm = normalize(v);
    expectVector2Values(-0.707107, -0.707107, norm);
    // normalizing a zero vector returns a zero vector
    v.x = 0; v.y = 0;
    norm = normalize(v);
    expectVector2Values(0, 0, norm);
}

TEST(Vector2Test, Distance)
{
    Vector2 v1{ -7, -4 }, v2{ 17, 6.5 };
    EXPECT_FLOAT_EQ(26.196374, dist(v1, v2));
    // distance between a vector and itself is zero
    EXPECT_FLOAT_EQ(0, dist(v1, v1));
}

TEST(Vector2Test, DistanceSquared)
{
    Vector2 v1{ 2, -9 }, v2{ -4, 1 };
    EXPECT_FLOAT_EQ(136.000004905, distSq(v1, v2));
    // distance squared between a vector and itself is zero
    EXPECT_FLOAT_EQ(0, distSq(v1, v1));
}

TEST(Vector2Test, Min)
{
    Vector2 result;
    result = min(Vector2{1, 2}, Vector2{2, 1});
    expectVector2Values(1, 1, result);
    result = min(Vector2{ 1, 2 }, Vector2{ 0, 0 }, Vector2{ -1, -1 }, Vector2{-2, -2});
    expectVector2Values(-2, -2, result);
}

TEST(Vector2Test, Max)
{
    Vector2 result;
    result = max(Vector2{ 1, 2 }, Vector2{ 2, 1 });
    expectVector2Values(2, 2, result);
    result = max(Vector2{ 1, 2 }, Vector2{ 0, 0 }, Vector2{ -1, -1 }, Vector2{ -2, -2 });
    expectVector2Values(1, 2, result);
}

TEST(Vector2Test, ScalarProduct)
{
    EXPECT_FLOAT_EQ(11, dot(Vector2{ 1, 2 }, Vector2{1, 5}));
    EXPECT_FLOAT_EQ(11, dot(Vector2{ 1, 5 }, Vector2{ 1, 2 }));
    // Scalar product with a zero vector results in zero.
    EXPECT_FLOAT_EQ(0, dot(Vector2{ -1, 2 }, Vector2{ 0, 0 }));
    EXPECT_FLOAT_EQ(0, dot(Vector2{ 0, 0 }, Vector2{ 5, 12 }));
    // negative values
    EXPECT_FLOAT_EQ(9, dot(Vector2{ -1, 2 }, Vector2{ 1, 5 }));
    EXPECT_FLOAT_EQ(-9.4, dot(Vector2{ 1, -5.2 }, Vector2{ 1, 2 }));
}

TEST(Vector2Test, Projection)
{
    expectVector2Values(1.8, 3.6, project(Vector2{ -1, 5 }, Vector2{ 2, 4 }));
    expectVector2Values(-2.6, -5.2, project(Vector2{ 3, -8 }, Vector2{ 1, 2 }));
    // projection using zero vectors results in zero vectors
    expectVector2Values(0, 0, project(Vector2{ -1, 5 }, Vector2{ 0, 0 }));
    expectVector2Values(0, 0, project(Vector2{ 0, 0 }, Vector2{ 2, 4 }));
}

TEST(Vector2Test, Deprojection)
{
    Vector2 b{ 2, 4 }, a{ -1, 5 };
    Vector2 proj = project(a, b);
    Vector2 expected = a - proj;
    expectVector2Values(expected.x, expected.y, deproject(a, b));
    a = Vector2{ 1, 2 }; b = Vector2{ 3, -8 };
    proj = project(a, b);
    expected = a - proj;
    expectVector2Values(expected.x, expected.y, deproject(a, b));
    // deprojection using zero vectors results in zero vectors
    expectVector2Values(0, 0, project(Vector2{ -1, 5 }, Vector2{ 0, 0 }));
    expectVector2Values(0, 0, project(Vector2{ 0, 0 }, Vector2{ 2, 4 }));
}

TEST(Vector2Test, Reflection)
{
    Vector2 i{-2, 0}, n{1, 1};
    expectVector2Values(2, 4, reflect(i, n));
}

TEST(Vector2Test, Refraction)
{
    Vector2 i{ -2, 0 }, n{ 1, 1 };
    expectVector2Values(-2.7838821, 0.21611786, refract(i, n, 1.5));
}
