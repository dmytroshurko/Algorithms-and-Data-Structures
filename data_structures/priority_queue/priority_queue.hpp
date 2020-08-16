#ifndef DATA_STRUCTURES_PRIORITY_QUEUE_PRIORITY_QUEUE_H_
#define DATA_STRUCTURES_PRIORITY_QUEUE_PRIORITY_QUEUE_H_

#include <cstddef>

#include "node.hpp"

namespace ds {

  const size_t kMinCapacity = 16;
  const int kGrowthFactor = 2;
  const int kShrinkFactor = 4;

  template <class T>
  class PriorityQueue {
  public:
    PriorityQueue();
    ~PriorityQueue();

    // Returns the number of elements in the priority queue.
    size_t GetSize() const;

    // Returns true if the priority queue contains no elements.
    bool IsEmpty() const;

    // Returns an element with maximum priority, without removing it.
    T GetMax() const;

    // Adds a new element with a given priority.
    void Insert(int priority, T element);

    // Extracts an element with maximum priority.
    T ExtractMax();

  private:
    int capacity_;
    size_t size_;
    Node<T>* array_;

    // Returns an index of the parent of the element with a given index.
    size_t Parent(size_t index);

    // Returns an index of the left child of the element with a given index.
    size_t LeftChild(size_t index);

    // Returns an index of the right child of the element with a given index.
    size_t RightChild(size_t index);

    void SiftUp(size_t index);
    void SiftDown(size_t index);

    void ResizeArray(size_t new_size);
    void IncreaseCapacity();
    void DecreaseCapacity();
  };

}  // namespace ds

#endif  // DATA_STRUCTURES_PRIORITY_QUEUE_PRIORITY_QUEUE_H_
