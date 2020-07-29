#ifndef DATA_STRUCTURES_LINKED_LIST_DOUBLY_LINKED_LIST_H_
#define DATA_STRUCTURES_LINKED_LIST_DOUBLY_LINKED_LIST_H_

#include "node.hpp"

namespace ds {

  template <class T>
  class DoublyLinkedList {
  public:
    DoublyLinkedList();
    ~DoublyLinkedList();

    // Returns the number of elements in this doubly linked list.
    int GetSize() const;

    // Returns true if this doubly linked list contains no elements.
    bool IsEmpty() const;

    // Adds a new value to the front of this doubly linked list.
    void PushFront(const T& value);

    // Returns the element at the front of this doubly linked list.
    T TopFront() const;

    // Removes and returns the first value of this doubly linked list.
    T PopFront();

    // Adds a new value to the end of this doubly linked list.
    void PushBack(const T& value);

    // Returns the element at the back of this doubly linked list.
    T TopBack() const;

    // Removes and returns the last value of this doubly linked list.
    T PopBack();

    // Returns true if this doubly linked list contains the value.
    bool Find(const T& value) const;

    // Removes the first occurrence of the value from the doubly linked list.
    void Remove(const T& value);

  private:
    int size_;
    Node<T>* head_;
    Node<T>* tail_;
  };

}  // namespace ds

#endif  // DATA_STRUCTURES_LINKED_LIST_DOUBLY_LINKED_LIST_H_
