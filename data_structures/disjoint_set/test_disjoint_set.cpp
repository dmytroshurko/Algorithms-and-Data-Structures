#include "disjoint_set.hpp"
#include "gtest/gtest.h"

TEST(DisjointSetTest, SimpleCheck) {
  ds::DisjointSet disjoint_set(8);
  for (int i = 0; i < 8; ++i) {
    disjoint_set.MakeSet(i);
  }

  disjoint_set.Union(0, 1);
  disjoint_set.Union(1, 4);
  disjoint_set.Union(4, 5);
  disjoint_set.Union(5, 7);

  ASSERT_EQ(disjoint_set.Find(0), disjoint_set.Find(5));
  ASSERT_TRUE(disjoint_set.IsReachable(0, 7));

  disjoint_set.Union(2, 3);

  ASSERT_FALSE(disjoint_set.IsReachable(0, 3));
  ASSERT_FALSE(disjoint_set.IsReachable(3, 6));
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
