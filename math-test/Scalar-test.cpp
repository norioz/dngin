#include "pch.h"
#include "../math/Scalar.h"

void testLogicalEqual(Scalar a, Scalar b)
{
    EXPECT_TRUE(a == b);
    EXPECT_TRUE(a >= b);
    EXPECT_TRUE(a <= b);
}

void testLogicalLessThan(Scalar less, Scalar greater)
{
    EXPECT_FALSE(less == greater);
    EXPECT_TRUE(less != greater);
    EXPECT_TRUE(greater > less);
    EXPECT_TRUE(greater >=  less);
    EXPECT_TRUE(less < greater);
    EXPECT_TRUE(less <= greater);
}

TEST(ScalarTest, ScalarInit)
{
    Scalar s(1.0);
    EXPECT_FLOAT_EQ(1.0, s);
}

TEST(ScalarTest, Equality)
{
    testLogicalEqual(1, 1);
    testLogicalEqual(1.1, 1.1);
    testLogicalEqual(1.11, 1.11);
    testLogicalEqual(1.111, 1.111);
    testLogicalEqual(1.1111, 1.1111);
}

TEST(ScalarTest, Inequality)
{
    testLogicalLessThan(0, 1);
    testLogicalLessThan(0, 0.1);
    testLogicalLessThan(0, 0.01);
    testLogicalLessThan(0, 0.001);
    testLogicalLessThan(0, 0.0001);
    testLogicalLessThan(0, 0.00001);
    testLogicalLessThan(-1, 0);
    testLogicalLessThan(-0.1, 0);
    testLogicalLessThan(-0.01, 0);
    testLogicalLessThan(-0.001, 0);
    testLogicalLessThan(-0.0001, 0);
    testLogicalLessThan(-0.00001, 0);
}

TEST(ScalarTest, Min)
{
    EXPECT_FLOAT_EQ(0.1, min(1, 0.1, 2));
    EXPECT_FLOAT_EQ(-1.01, min(0, -1, -1.01));
    EXPECT_FLOAT_EQ(100, min(100, 1000, 2000));
    EXPECT_FLOAT_EQ(-1, min(1, 0.1, 2, 100000, -1));
    EXPECT_FLOAT_EQ(0, min(0, 0.1));
    EXPECT_FLOAT_EQ(0.1, min(0.1, 0.1, 2));
    EXPECT_FLOAT_EQ(1, min(1, 2, 2, 2, 1));
}

TEST(ScalarTest, Max)
{
    EXPECT_FLOAT_EQ(1, max(0, 0, 1));
    EXPECT_FLOAT_EQ(1000, max(10, 100, 1000));
    EXPECT_FLOAT_EQ(10000.1, max(0, 1000, 10000.1));
    EXPECT_FLOAT_EQ(0.1, max(-1, -100, 0.1));
    EXPECT_FLOAT_EQ(0.0001, max(0, 0.0001));
    EXPECT_FLOAT_EQ(1, max(0, 0, 1, 1));
}

TEST(ScalarTest, Snap)
{
    EXPECT_FLOAT_EQ(1, snap(1.1, 1, 2));
    // Expect that midpoint snaps round down, not up.
    EXPECT_FLOAT_EQ(1, snap(1.5, 1, 2));
}

TEST(ScalarTest, Clamp)
{
    EXPECT_FLOAT_EQ(1, clamp(1, 0, 2));
    // Expect that a value blow the range returns the min.
    EXPECT_FLOAT_EQ(0, clamp(-1, 0, 2));
    // Expect that a value above the range returns the max.
    EXPECT_FLOAT_EQ(2, clamp(100, 0, 2));
}

TEST(ScalarTest, Lerp)
{
    EXPECT_FLOAT_EQ(1.5, lerp(1, 2, 0.5));
    EXPECT_FLOAT_EQ(2, lerp(1, 3, 0.5));
    EXPECT_FLOAT_EQ(0.75, lerp(0, 1, 0.75));
    EXPECT_FLOAT_EQ(0, lerp(-1, 1, 0.5));
    // If a and b are the same, the interp value doesn't matter.
    EXPECT_FLOAT_EQ(1, lerp(1, 1, 0.7));
    EXPECT_FLOAT_EQ(2, lerp(2, 2, 0.9));
    EXPECT_FLOAT_EQ(3, lerp(3, 3, 10));
    // The interp value is not clamped.
    EXPECT_FLOAT_EQ(11, lerp(1, 2, 10));
    EXPECT_FLOAT_EQ(-9, lerp(1, 2, -10));
    // The order of a and b doesn't matter.
    EXPECT_FLOAT_EQ(1.5, lerp(2, 1, 0.5));
}
