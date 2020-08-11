#include "gtest/gtest.h"
#include "stack.hpp"

TEST(StackTest, EmptyStack) {
  bool test_passed;
  ds::Stack<int> stack;
  test_passed = stack.IsEmpty();
  stack.Push(100);
  test_passed = test_passed && !stack.IsEmpty();
  ASSERT_TRUE(test_passed);
}

TEST(StackTest, StackPushPop) {
  bool test_passed;
  ds::Stack<int> stack;
  stack.Push(-1);
  stack.Push(2);
  stack.Push(40);
  test_passed = stack.Pop() == 40;
  test_passed &= stack.Pop() == 2;
  test_passed &= stack.Pop() == -1;
  ASSERT_TRUE(test_passed);
}

TEST(StackTest, OneHundredElements) {
  bool test_passed;
  ds::Stack<int> stack;
  for (int i = 1; i <= 100; ++i) {
    stack.Push(i);
  }
  ASSERT_EQ(100, stack.GetSize());

  test_passed = !stack.IsEmpty();
  for (int i = 100; i > 0; --i) {
    test_passed &= stack.Pop() == i;
  }
  test_passed &= stack.IsEmpty();
  ASSERT_TRUE(test_passed);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
