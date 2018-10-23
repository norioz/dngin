#include "pch.h"
#include "../math/Scalar.h"

TEST(ScalarTest, ScalarInit) {
    Scalar s(1.0);
    EXPECT_FLOAT_EQ(1.0, s);
}
