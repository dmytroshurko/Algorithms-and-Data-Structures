#ifndef DATA_STRUCTURES_DYNAMIC_ARRAY_DYNAMIC_ARRAY_H_
#define DATA_STRUCTURES_DYNAMIC_ARRAY_DYNAMIC_ARRAY_H_

#include <algorithm>
#include <initializer_list>
#include <stdexcept>

namespace ds {

  const int kMinCapacity = 16;
  const int kGrowthFactor = 2;
  const int kShrinkFactor = 4;

  template <class T> class DynamicArray {
  public:
    DynamicArray();
    DynamicArray(int capacity);
    DynamicArray(std::initializer_list<T> init_list);
    ~DynamicArray();

    // Returns the number of elements in the dynamic array.
    int GetSize() const;

    // Returns true if the dynamic array is empty.
    bool IsEmpty() const;

    // Returns the element at the specified index position.
    T Get(int index) const;

    // Sets the element at the specified index to the new value.
    void Set(int index, T value);

    // Adds a new element at the end of the dynamic array.
    void Append(T value);

    // Inserts the new element at the specified index position.
    void InsertAt(int index, T value);

    // Deletes the element at the specified index position.
    void RemoveAt(int index);

  private:
    int capacity_;
    int size_;
    T* array_;

    void ResizeArray(int new_size);
    void IncreaseCapacity();
    void DecreaseCapacity();
  };

}  // namespace ds

#endif  // DATA_STRUCTURES_DYNAMIC_ARRAY_DYNAMIC_ARRAY_H_
