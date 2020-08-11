#ifndef DATA_STRUCTURES_STACK_STACK_H_
#define DATA_STRUCTURES_STACK_STACK_H_

#include <stdexcept>

namespace ds {

  const int kMinCapacity = 16;
  const int kGrowthFactor = 2;
  const int kShrinkFactor = 4;

  template <class T>
  class Stack {
  public:
    Stack();
    ~Stack() = default;

    // Returns the number of elements in this stack.
    int GetSize() const;

    // Returns true if this stack contains no elements.
    bool IsEmpty() const;

    // Pushes the specified value onto this stack.
    void Push(T value);

    // Returns the value of top element from this stack, without removing it.
    T Top();

    // Removes the top element from this stack and returns it.
    T Pop();

  private:
    int capacity_;
    int size_;
    T* array_;

    void ResizeArray(int new_size);
    void IncreaseCapacity();
    void DecreaseCapacity();
  };

}  // namespace ds

#endif  // DATA_STRUCTURES_STACK_STACK_H_
