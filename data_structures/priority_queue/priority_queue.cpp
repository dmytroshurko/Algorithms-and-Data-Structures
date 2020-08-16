#include "priority_queue.hpp"

#include <cmath>
#include <stdexcept>
#include <utility>

namespace ds {

  template <class T>
  PriorityQueue<T>::PriorityQueue()
      : capacity_(kMinCapacity), size_(0), array_(new Node<T>[kMinCapacity]) {}

  template <class T>
  PriorityQueue<T>::~PriorityQueue() {
    delete[] array_;
  }

  template <class T>
  size_t PriorityQueue<T>::GetSize() const {
    return size_;
  }

  template <class T>
  bool PriorityQueue<T>::IsEmpty() const {
    return size_ == 0;
  }

  template <class T>
  T PriorityQueue<T>::GetMax() const {
    if (size_ == 0) {
      throw std::length_error("Priority Queue is empty.");
    }

    return array_[0].GetData();
  }

  template <class T>
  void PriorityQueue<T>::Insert(int priority, T element) {
    ResizeArray(size_ + 1);

    Node<T> node(priority, element);
    array_[size_++] = node;
    SiftUp(size_ - 1);
  }

  template <class T>
  T PriorityQueue<T>::ExtractMax() {
    if (size_ == 0) {
      throw std::length_error("Priority Queue is empty.");
    }

    ResizeArray(size_ - 1);
    T result = array_[0].GetData();
    array_[0] = array_[--size_];
    SiftDown(0);
    return result;
  }

  template <class T>
  size_t PriorityQueue<T>::Parent(size_t index) {
    return floor((index - 1) / 2);
  }

  template <class T>
  size_t PriorityQueue<T>::LeftChild(size_t index) {
    return 2 * index + 1;
  }

  template <class T>
  size_t PriorityQueue<T>::RightChild(size_t index) {
    return 2 * index + 2;
  }

  template <class T>
  void PriorityQueue<T>::SiftUp(size_t index) {
    while (index > 0 && array_[Parent(index)].GetPriority() < array_[index].GetPriority()) {
      std::swap(array_[Parent(index)], array_[index]);
      index = Parent(index);
    }
  }

  template <class T>
  void PriorityQueue<T>::SiftDown(size_t index) {
    size_t max_index = index;

    size_t l = LeftChild(index);
    if (l < size_ && array_[l].GetPriority() > array_[max_index].GetPriority()) {
      max_index = l;
    }

    size_t r = RightChild(index);
    if (r < size_ && array_[r].GetPriority() > array_[max_index].GetPriority()) {
      max_index = r;
    }

    if (index != max_index) {
      std::swap(array_[index], array_[max_index]);
      SiftDown(max_index);
    }
  }

  template <class T>
  void PriorityQueue<T>::ResizeArray(size_t new_size) {
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
  void PriorityQueue<T>::IncreaseCapacity() {
    size_t new_capacity = capacity_ * kGrowthFactor;
    capacity_ = new_capacity;
    Node<T>* new_array = new Node<T>[new_capacity];
    for (size_t i = 0; i < size_; ++i) {
      new_array[i] = array_[i];
    }
    delete[] array_;
    array_ = new_array;
  }

  template <class T>
  void PriorityQueue<T>::DecreaseCapacity() {
    size_t new_capacity = capacity_ / kShrinkFactor;
    if (new_capacity < kMinCapacity) {
      new_capacity = kMinCapacity;
    }
    capacity_ = new_capacity;
    Node<T>* new_array = new Node<T>[new_capacity];
    for (size_t i = 0; i < size_; ++i) {
      new_array[i] = array_[i];
    }
    delete[] array_;
    array_ = new_array;
  }

}  // namespace ds

template class ds::PriorityQueue<int>;
template class ds::PriorityQueue<float>;
template class ds::PriorityQueue<double>;
template class ds::PriorityQueue<std::string>;
