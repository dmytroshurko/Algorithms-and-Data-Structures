#include <string>

#include "gtest/gtest.h"
#include "priority_queue.hpp"

TEST(PriorityQueueTest, OneElement) {
  bool test_passed;
  ds::PriorityQueue<std::string> p_queue;
  test_passed = p_queue.IsEmpty();
  p_queue.Insert(0, "Hello, World!");
  test_passed = test_passed && !p_queue.IsEmpty();
  ASSERT_TRUE(test_passed);
}

TEST(PriorityQueue, SimpleCheck) {
  bool test_passed;
  ds::PriorityQueue<std::string> p_queue;
  p_queue.Insert(4, "\"Surely You're Joking, Mr. Feynman!\": Adventures of a Curious Character");
  p_queue.Insert(2, "Foundation");
  p_queue.Insert(1, "Foundation and Empire");
  p_queue.Insert(0, "Second Foundation");
  p_queue.Insert(3, "How Not to Be Wrong: The Power of Mathematical Thinking");
  test_passed = p_queue.ExtractMax()
                == "\"Surely You're Joking, Mr. Feynman!\": Adventures of a Curious Character";
  test_passed &= p_queue.ExtractMax() == "How Not to Be Wrong: The Power of Mathematical Thinking";
  test_passed &= p_queue.ExtractMax() == "Foundation";
  test_passed &= p_queue.ExtractMax() == "Foundation and Empire";
  test_passed &= p_queue.ExtractMax() == "Second Foundation";
  ASSERT_TRUE(test_passed);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
