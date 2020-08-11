#include "stack.hpp"

#include <string>

namespace ds {

  template <class T>
  Stack<T>::Stack() : capacity_(kMinCapacity), size_(0), array_(new T[kMinCapacity]) {}

  template <class T>
  int Stack<T>::GetSize() const {
    return size_;
  }

  template <class T>
  bool Stack<T>::IsEmpty() const {
    return size_ == 0;
  }

  template <class T>
  void Stack<T>::Push(T value) {
    ResizeArray(size_ + 1);
    array_[size_++] = value;
  }

  template <class T>
  T Stack<T>::Top() {
    if (size_ == 0) {
      throw std::out_of_range("Stack is empty.");
    }

    return array_[size_ - 1];
  }

  template <class T>
  T Stack<T>::Pop() {
    if (size_ == 0) {
      throw std::out_of_range("Stack is empty.");
    }

    ResizeArray(size_ - 1);
    T value = array_[--size_];
    return value;
  }

  template <class T>
  void Stack<T>::ResizeArray(int new_size) {
    if (size_ < new_size) {
      if (size_ == capacity_) {
        IncreaseCapacity();
      }
    } else if (size_ > new_size) {
      if (size_ < capacity_ / kShrinkFactor) {
        DecreaseCapacity();
      }
    }
  }

  template <class T>
  void Stack<T>::IncreaseCapacity() {
    int new_capacity = capacity_ * kGrowthFactor;
    capacity_ = new_capacity;
    T* new_array = new T[new_capacity];
    for (int i = 0; i < size_; ++i) {
      new_array[i] = array_[i];
    }
    delete[] array_;
    array_ = new_array;
  }

  template <class T>
  void Stack<T>::DecreaseCapacity() {
    int new_capacity = capacity_ / kShrinkFactor;
    if (new_capacity < kMinCapacity) {
      new_capacity = kMinCapacity;
    }
    capacity_ = new_capacity;
    T* new_array = new T[new_capacity];
    for (int i = 0; i < size_; ++i) {
      new_array[i] = array_[i];
    }
    delete[] array_;
    array_ = new_array;
  }

}  // namespace ds

template class ds::Stack<int>;
template class ds::Stack<float>;
template class ds::Stack<double>;
template class ds::Stack<std::string>;
