#include <lambda_fun/pair.h>

#include <gtest/gtest.h>

using namespace lambda_fun;

TEST(PairTest, TestGTest) { ASSERT_TRUE(true); }

TEST(PairTest, Pairs) {
    auto p = Pair(1, 2);
    auto i = Fst(p);
    auto j = Snd(p);
    ASSERT_EQ(i, 1);
    ASSERT_EQ(j, 2);
}

TEST(PairTest, Swap) {
    auto p = Pair(3, 2);
    auto s = Swap(p);
    ASSERT_EQ(Fst(s), 2);
    ASSERT_EQ(Snd(s), 3);
}
