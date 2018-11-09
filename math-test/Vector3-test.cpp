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

TEST(Vector3Test, Magnitude)
{
    EXPECT_FLOAT_EQ(10.049876, magnitude(Vector3{ 1, 0, -10 }));
    EXPECT_FLOAT_EQ(4.8989795, magnitude(Vector3{ 2, 4, -2 }));
}

// 

TEST(Vector3Test, Normalize)
{
    Vector3 v{ 1, 1, 1 };
    Vector3 norm = normalize(v);
    expectVector3Values(0.5773503, 0.5773503, 0.5773503, norm);
    // a unit vector should normalize to itself
    v.x = 0.57735026919; v.y = 0.5773503, v.z = 0.5773503;
    norm = normalize(v);
    expectVector3Values(0.5773503, 0.5773503, 0.5773503, norm);
    // unit vector points in the direction of the original
    v.x = -1; v.y = -1, v.z = -1;
    norm = normalize(v);
    expectVector3Values(-0.5773503, -0.5773503, -0.5773503, norm);
    // normalizing a zero vector returns a zero vector
    v.x = 0; v.y = 0, v.z = 0;
    norm = normalize(v);
    expectVector3Values(0, 0, 0, norm);
}

TEST(Vector3Test, Distance)
{
    Vector3 v1{ 7, 4, -3 }, v2{ 17, 6.1, 2 };
    EXPECT_FLOAT_EQ(11.375852, dist(v1, v2));
    // distance between a vector and itself is zero
    EXPECT_FLOAT_EQ(0, dist(v1, v1));
}

TEST(Vector3Test, DistanceSquared)
{
    Vector3 v1{ 7, 4, -3 }, v2{ 17, 6.1, 2 };
    EXPECT_FLOAT_EQ(129.4100087, distSq(v1, v2));
    // distance squared between a vector and itself is zero
    EXPECT_FLOAT_EQ(0, distSq(v1, v1));
}

TEST(Vector3Test, Min)
{
    Vector3 result;
    result = min(Vector3{ 1, 2, 4.1 }, Vector3{ 2, 1, 4.2 });
    expectVector3Values(1, 1, 4.1, result);
    result = min(Vector3{ 1, 2, -1.1 }, Vector3{ 0, 0, 0 }, Vector3{ -1, -1, -1 }, Vector3{ -2, -2, -2 });
    expectVector3Values(-2, -2, -2, result);
}

TEST(Vector3Test, Max)
{
    Vector3 result;
    result = max(Vector3{ 1, 2, 4.1 }, Vector3{ 2, 1, 4.2 });
    expectVector3Values(2, 2, 4.2, result);
    result = max(Vector3{ 1, 2, -1.1 }, Vector3{ 0, 0, 0 }, Vector3{ -1, -1, -1 }, Vector3{ -2, -2, -2 });
    expectVector3Values(1, 2, 0, result);
}

TEST(Vector3Test, ScalarProduct)
{
    // order of vectors doesn't matter
    EXPECT_FLOAT_EQ(20, sprod(Vector3{ 1, 2, 3 }, Vector3{ 1, 5, 3 }));
    EXPECT_FLOAT_EQ(20, sprod(Vector3{ 1, 5, 3 }, Vector3{ 1, 2, 3 }));
    // scalar product with a zero vector results in zeros
    EXPECT_FLOAT_EQ(0, sprod(Vector3{ -1, 2, 1000 }, Vector3{ 0, 0, 0 }));
    EXPECT_FLOAT_EQ(0, sprod(Vector3{ 0, 0, 0 }, Vector3{ 5, 12, -111 }));
    // negative values
    EXPECT_FLOAT_EQ(18, sprod(Vector3{ -1, 2, 3 }, Vector3{ 1, 5, 3 }));
    EXPECT_FLOAT_EQ(-7.4, sprod(Vector3{ 1, -5.2, 2 }, Vector3{ 1, 2, 1 }));
}

TEST(Vector3Test, CrossProduct)
{
    Vector3 v0{ 1, 2, 3 }, v1{ 1, 5, 7 };
    expectVector3Values(-1, -4, 3, cross(v0, v1));
    // order matters
    expectVector3Values(1, 4, -3, cross(v1, v0));
    // cross with a zero vector
    v0.x = 0, v0.y = 0, v0.z = 0;
    expectVector3Values(0, 0, 0, cross(v0, v1));
    expectVector3Values(0, 0, 0, cross(v1, v0));
}

TEST(Vector3Test, Projection)
{
    expectVector3Values(0.5, 0, 1.5, project(Vector3{ -1, 4, 2 }, Vector3{ 1, 0, 3 }));
    expectVector3Values(-1.0588235, -1.4117647, 1.0588235, project(Vector3{ 2, 0, 6 }, Vector3{ 3, 4, -3 }));
    // projection using zero vectors results in zero vectors
    expectVector3Values(0, 0, 0, project(Vector3{ 0, 0, 0 }, Vector3{ -1, 5, 1.1 }));
    expectVector3Values(0, 0, 0, project(Vector3{ 2, 4, -5.2 }, Vector3{ 0, 0, 0 }));
}

TEST(Vector3Test, Deprojection)
{
    Vector3 b{ 2, 4, -7 }, a{ -1, 5, 1.1 };
    Vector3 proj = project(a, b);
    Vector3 expected = a - proj;
    expectVector3Values(expected.x, expected.y, expected.z, deproject(a, b));
    a = Vector3{ 1, 2, -0.2 }; b = Vector3{ 3, -8, 0 };
    proj = project(a, b);
    expected = a - proj;
    expectVector3Values(expected.x, expected.y, expected.z, deproject(a, b));
    // deprojection using zero vectors results in zero vectors
    expectVector3Values(0, 0, 0, project(Vector3{ -1, 5 }, Vector3{ 0, 0, 0 }));
    expectVector3Values(0, 0, 0, project(Vector3{ 0, 0, 0 }, Vector3{ 2, 4 }));
}

TEST(Vector3Test, Reflection)
{
    Vector3 i{ -2, 0, 1 }, n{ 1, 1, 1 };
    expectVector3Values(0, 2, 3, reflect(i, n));
}

TEST(Vector3Test, Refraction)
{
    Vector3 i{ -2, 0, 1 }, n{ 1, 1, 1 };
    expectVector3Values(-2.5, 0.5, 2, refract(i, n, 1.5));
}
