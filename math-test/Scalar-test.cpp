#include "pch.h"
#include "../dngin/Scalar.h"

TEST(ScalarTest, ScalarInit) {
    Scalar s(1.0);
    EXPECT_FLOAT_EQ(1.0, s);
}
