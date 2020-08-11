#include "queue.hpp"

#include <string>

namespace ds {

  template <class T>
  Queue<T>::Queue() : size_(0), head_(nullptr), tail_(nullptr) {}

  template <class T>
  Queue<T>::~Queue() {
    Node<T>* current = head_;
    Node<T>* next = nullptr;

    while (current) {
      next = current->GetNext();
      delete current;
      current = next;
    }
  }

  template <class T>
  int Queue<T>::GetSize() const {
    return size_;
  }

  template <class T>
  bool Queue<T>::IsEmpty() const {
    return head_ == nullptr;
  }

  template <class T>
  void Queue<T>::Enqueue(T value) {
    Node<T>* node = new Node<T>(value);
    if (tail_ == nullptr) {
      head_ = tail_ = node;
    } else {
      tail_->SetNext(node);
      tail_ = node;
    }
    ++size_;
  }

  template <class T>
  T Queue<T>::Top() {
    if (head_ == nullptr) {
      throw std::length_error("Queue is empty");
    }

    return head_->GetValue();
  }

  template <class T>
  T Queue<T>::Dequeue() {
    if (head_ == nullptr) {
      throw std::length_error("Queue is empty");
    }

    T value = head_->GetValue();
    head_ = head_->GetNext();
    if (head_ == nullptr) {
      tail_ = nullptr;
    }
    --size_;
    return value;
  }

}  // namespace ds

template class ds::Queue<int>;
template class ds::Queue<float>;
template class ds::Queue<double>;
template class ds::Queue<std::string>;