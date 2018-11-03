#include "pch.h"
#include "../math/Vector.h"

TEST(Vector2Test, Vector2Init)
{
    Vector2 v0{ 0, 1 };
    EXPECT_FLOAT_EQ(0, v0.x);
    EXPECT_FLOAT_EQ(1, v0.y);
    Vector2 v1 = { 2, 3 };
    EXPECT_FLOAT_EQ(2, v1.x);
    EXPECT_FLOAT_EQ(3, v1.y);
}
