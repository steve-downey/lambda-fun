#include <lambda_fun/boolean.h>

#include <gtest/gtest.h>

using namespace lambda_fun;

TEST(BooleanTest, TestGTest) { ASSERT_EQ(1, 1); }

TEST(BooleanTest, Booleans) {
    ASSERT_TRUE(toBool(True)());
    ASSERT_FALSE(toBool(False)());

    ASSERT_TRUE(toBool(And(True, True))());
    ASSERT_FALSE(toBool(And(True, False))());
    ASSERT_FALSE(toBool(And(False, True))());
    ASSERT_FALSE(toBool(And(False, False))());

    ASSERT_TRUE(toBool(Or(True, True))());
    ASSERT_TRUE(toBool(Or(True, True))());
    ASSERT_TRUE(toBool(Or(False, True))());
    ASSERT_FALSE(toBool(Or(False, False))());

    ASSERT_TRUE(toBool(Not(False))());
    ASSERT_FALSE(toBool(Not(True))());

    ASSERT_TRUE(toBool(Not(Or(False, False)))());
}
