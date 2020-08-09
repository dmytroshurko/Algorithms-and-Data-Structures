#include <vector>

#include "doubly_linked_list.hpp"
#include "gtest/gtest.h"

TEST(DoublyLinkedListTest, EmptyList) {
  ds::DoublyLinkedList<int> list;
  ASSERT_TRUE(list.IsEmpty());
  ASSERT_EQ(0, list.GetSize());
}

TEST(DoublyLinkedListTest, OneElement) {
  ds::DoublyLinkedList<int> list;
  list.PushFront(0);
  ASSERT_EQ(1, list.GetSize());
  ASSERT_TRUE(list.TopFront() == list.TopBack() && list.TopBack() == 0);
}

TEST(DoublyLinkedListTest, PushPopElements) {
  ds::DoublyLinkedList<int> list;
  for (int i = 0; i < 10; ++i) {
    list.PushBack(i);
  }
  for (int i = 0; i < 10; ++i) {
    list.PushFront(i);
  }
  ASSERT_EQ(20, list.GetSize());

  for (int i = 0; i < 10; ++i) {
    ASSERT_EQ(list.PopFront(), list.PopBack());
  }
  ASSERT_TRUE(list.IsEmpty());
  ASSERT_EQ(0, list.GetSize());
}

TEST(DoublyLinkedListTest, FindElements) {
  ds::DoublyLinkedList<int> list;
  for (int i = 0; i < 10; ++i) {
    list.PushBack(i);
  }
  ASSERT_TRUE(list.Find(5));
  ASSERT_FALSE(list.Find(1000));
}

TEST(DoublyLinkedListTest, RemoveElement) {
  std::vector<int> vec1{0, 1, 2, 3, 3, 4, 5};
  std::vector<int> vec2{0, 1, 2, 3, 4, 5};
  ds::DoublyLinkedList<int> list;
  for (int val : vec1) {
    list.PushBack(val);
  }
  ASSERT_EQ(vec1.size(), list.GetSize());

  list.Remove(3);
  ASSERT_EQ(vec2.size(), list.GetSize());
  for (int i = 0; i < vec2.size(); ++i) {
    ASSERT_EQ(list.PopFront(), vec2[i]);
  }
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
