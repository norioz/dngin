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
