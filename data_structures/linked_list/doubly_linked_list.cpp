#include "doubly_linked_list.hpp"

#include <stdexcept>
#include <string>

namespace ds {

  template <class T>
  DoublyLinkedList<T>::DoublyLinkedList() : size_(0), head_(nullptr), tail_(nullptr) {}

  template <class T>
  DoublyLinkedList<T>::~DoublyLinkedList() {
    Node<T>* current = head_;
    Node<T>* next = nullptr;

    while (current) {
      next = current->GetNext();
      delete current;
      current = next;
    }
  }

  template <class T>
  int DoublyLinkedList<T>::GetSize() const {
    return size_;
  }

  template <class T>
  bool DoublyLinkedList<T>::IsEmpty() const {
    return head_ == nullptr;
  }

  template <class T>
  void DoublyLinkedList<T>::PushFront(const T& value) {
    Node<T>* node = new Node<T>(value);
    // if the list is empty, the head doesn't point anything
    if (head_ == nullptr) {
      head_ = tail_ = node;
    } else {
      head_->SetPrev(node);
      node->SetNext(head_);
      head_ = node;
    }
    ++size_;
  }

  template <class T>
  T DoublyLinkedList<T>::TopFront() const {
    if (head_ == nullptr) {
      throw std::out_of_range("List is empty");
    }

    return head_->GetValue();
  }

  template <class T>
  T DoublyLinkedList<T>::PopFront() {
    if (head_ == nullptr) {
      throw std::out_of_range("List is empty");
    }

    T value;
    // if there is only one element in the list
    if (head_ == tail_) {
      value = head_->GetValue();
      head_ = tail_ = nullptr;
    } else {
      value = head_->GetValue();
      head_ = head_->GetNext();
      head_->SetPrev(nullptr);
    }
    --size_;
    return value;
  }

  template <class T>
  void DoublyLinkedList<T>::PushBack(const T& value) {
    Node<T>* node = new Node<T>(value);
    // if the list is empty, the tail doesn't point anything
    if (tail_ == nullptr) {
      head_ = tail_ = node;
    } else {
      tail_->SetNext(node);
      node->SetPrev(tail_);
      tail_ = node;
    }
    ++size_;
  }

  template <class T>
  T DoublyLinkedList<T>::TopBack() const {
    if (head_ == nullptr) {
      throw std::out_of_range("List is empty");
    }

    return tail_->GetValue();
  }

  template <class T>
  T DoublyLinkedList<T>::PopBack() {
    if (head_ == nullptr) {
      throw std::out_of_range("List is empty");
    }

    T value;
    // if there is only one element in the list
    if (head_ == tail_) {
      value = head_->GetValue();
      head_ = tail_ = nullptr;
    } else {
      value = tail_->GetValue();
      tail_ = tail_->GetPrev();
      tail_->SetNext(nullptr);
    }
    --size_;
    return value;
  }

  template <class T>
  bool DoublyLinkedList<T>::Find(const T& value) const {
    Node<T>* current = head_;
    while (current != nullptr) {
      if (current->GetValue() == value) {
        return true;
      }
      current = current->GetNext();
    }
    return false;
  }

  template <class T>
  void DoublyLinkedList<T>::Remove(const T& value) {
    Node<T>* current = head_;
    while (current != nullptr) {
      if (current->GetValue() == value) {
        if (current->GetPrev() == nullptr) {
          // If is is the first (or only one) element in this doubly linked list
          PopFront();
        } else if (current->GetNext() == nullptr) {
          // If is is the last element in this doubly linked list
          PopBack();
        } else {
          // If this element is in the middle of this doubly linked list
          current->GetPrev()->SetNext(current->GetNext());
          current->GetNext()->SetPrev(current->GetPrev());
          --size_;
        }
        break;
      }
      current = current->GetNext();
    }
  }

}  // namespace ds

template class ds::DoublyLinkedList<int>;
template class ds::DoublyLinkedList<float>;
template class ds::DoublyLinkedList<double>;
template class ds::DoublyLinkedList<std::string>;
