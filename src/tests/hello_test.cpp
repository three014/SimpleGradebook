#include <gtest/gtest.h>

// Demonstrate some basic assertions.
TEST(HelloTest, BasicAssertions)
{
    // Expect two strings to not be equal
    EXPECT_STRNE("hello", "world");

    // Expect equality
    EXPECT_EQ(7 * 6, 42);
}
