#include "gtest/gtest.h"
#include "queue.hpp"

TEST(QueueTest, EmptyQueue) {
  bool test_passed;
  ds::Queue<int> queue;
  test_passed = queue.IsEmpty();
  queue.Enqueue(1000);
  test_passed = test_passed && !queue.IsEmpty();
  EXPECT_TRUE(test_passed);
}

TEST(QueueTest, QueueEnqueueDequeue) {
  bool test_passed;
  ds::Queue<int> queue;
  queue.Enqueue(1);
  queue.Enqueue(1000);
  queue.Enqueue(100);
  test_passed = queue.Dequeue() == 1;
  test_passed &= queue.Dequeue() == 1000;
  test_passed &= queue.Dequeue() == 100;
  EXPECT_TRUE(test_passed);
}

TEST(QueueTest, OneHundredElements) {
  bool test_passed;
  ds::Queue<int> queue;
  for (int i = 1; i <= 100; ++i) {
    queue.Enqueue(i);
  }
  ASSERT_EQ(100, queue.GetSize());

  test_passed = !queue.IsEmpty();
  for (int i = 1; i <= 100; ++i) {
    test_passed &= queue.Dequeue() == i;
  }
  test_passed &= queue.IsEmpty();
  EXPECT_TRUE(test_passed);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
