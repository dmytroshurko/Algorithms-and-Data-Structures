#ifndef DATA_STRUCTURES_QUEUE_QUEUE_H_
#define DATA_STRUCTURES_QUEUE_QUEUE_H_

#include <stdexcept>

#include "node.hpp"

namespace ds {

  template <class T>
  class Queue {
  public:
    Queue();
    ~Queue();

    // Returns the number of values in the queue.
    int GetSize() const;

    // Returns true if the queue contains no elements.
    bool IsEmpty() const;

    // Adds value to the end of the queue.
    void Enqueue(T value);

    // Returns the first value in the queue, without removing it.
    T Top();

    // Removes and returns the first element in the queue.
    T Dequeue();

  private:
    int size_;
    Node<T>* head_;
    Node<T>* tail_;
  };

}  // namespace ds

#endif  // DATA_STRUCTURES_QUEUE_QUEUE_H_
