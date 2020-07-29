#include "dynamic_array.hpp"
#include "gtest/gtest.h"

TEST(DynamicArrayTest, CopyConstructor) {
  ds::DynamicArray<int> arr1;
  for (int i = 0; i < 100; ++i) {
    arr1.Append(i);
  }

  ds::DynamicArray<int> arr2(arr1);

  ASSERT_EQ(arr1.GetSize(), arr2.GetSize());
  ASSERT_EQ(arr1.GetCapacity(), arr2.GetCapacity());

  for (int i = 0; i < arr1.GetSize(); ++i) {
    ASSERT_TRUE(arr1[i] == arr2[i]);
  }
}

TEST(DynamicArrayTest, CopyAssignment) {
  ds::DynamicArray<int> arr1;
  for (int i = 0; i < 100; ++i) {
    arr1.Append(i);
  }

  ds::DynamicArray<int> arr2{1, 2, 3, 4, 5};
  arr2 = arr1;

  ASSERT_EQ(arr1.GetSize(), arr2.GetSize());
  ASSERT_EQ(arr1.GetCapacity(), arr2.GetCapacity());

  for (int i = 0; i < arr1.GetSize(); ++i) {
    ASSERT_TRUE(arr1[i] == arr2[i]);
  }
}

TEST(DynamicArrayTest, IsEmpty) {
  ds::DynamicArray<int> arr;
  ASSERT_TRUE(arr.IsEmpty());
}

TEST(DynamicArrayTest, Capacity) {
  ds::DynamicArray<int> arr;
  ASSERT_EQ(ds::kMinCapacity, arr.GetCapacity());

  // increase capacity
  for (int i = 0; i < 20; ++i) {
    arr.Append(i);
  }
  ASSERT_EQ(ds::kMinCapacity * 2, arr.GetCapacity());

  // increase capacity
  for (int i = 0; i < 20; ++i) {
    arr.Append(i);
  }
  ASSERT_EQ(ds::kMinCapacity * 4, arr.GetCapacity());

  for (int i = 0; i < 20; ++i) {
    arr.RemoveAt(0);
  }
  ASSERT_EQ(ds::kMinCapacity * 4, arr.GetCapacity());

  // decrease capacity
  for (int i = 0; i < 10; ++i) {
    arr.RemoveAt(0);
  }
  ASSERT_EQ(ds::kMinCapacity, arr.GetCapacity());
}

TEST(DynamicArrayTest, Get) {
  ds::DynamicArray<int> arr;

  for (int i = 0; i < 100; ++i) {
    arr.Append(i);
  }

  for (int i = 0; i < arr.GetSize(); ++i) {
    ASSERT_TRUE(arr[i] == arr.Get(i));
  }
}

TEST(DynamicArrayTest, Set) {
  ds::DynamicArray<int> arr1{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  ds::DynamicArray<int> arr2{10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
  ds::DynamicArray<int> arr3(arr2);

  for (int i = 0; i < arr1.GetSize(); ++i) {
    arr2.Set(i, arr1[i]);
    arr3[i] = arr1[i];
  }

  for (int i = 0; i < arr1.GetSize(); ++i) {
    ASSERT_TRUE(arr1[i] == arr2[i] && arr1[i] == arr3[i]);
  }
}

TEST(DynamicArrayTest, InsertAt) {
  ds::DynamicArray<int> arr1{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  ds::DynamicArray<int> arr2 = {0};

  for (int i = 0; i < arr1.GetSize(); ++i) {
    arr2.InsertAt(i, arr1[i]);
  }

  for (int i = 0; i < arr1.GetSize(); ++i) {
    ASSERT_TRUE(arr1[i] == arr2[i]);
  }
}

TEST(DynamicArrayTest, RemoveAt) {
  ds::DynamicArray<int> arr;

  for (int i = 0; i < 100; ++i) {
    arr.Append(i);
  }

  while (!arr.IsEmpty()) {
    arr.RemoveAt(0);
  }

  ASSERT_TRUE(arr.IsEmpty());
  ASSERT_EQ(16, arr.GetCapacity());
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
