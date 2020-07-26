#include "dynamic_array.hpp"

#include <string>

namespace ds {
  template <class T> DynamicArray<T>::DynamicArray()
      : capacity_(kMinCapacity), size_(0), array_(new T[kMinCapacity]) {}

  template <class T> DynamicArray<T>::DynamicArray(int capacity) {
    if (capacity < 0) {
      throw std::length_error("Capacity can't be negative.");
    }
    capacity_ = capacity;
    size_ = 0;
    array_ = new T[capacity];
  }

  template <class T> DynamicArray<T>::DynamicArray(std::initializer_list<T> init_list)
      : capacity_(init_list.size() * kGrowthFactor),
        size_(init_list.size()),
        array_(new T[init_list.size()]) {
    std::copy(init_list.begin(), init_list.end(), array_);
  }

  template <class T> DynamicArray<T>::~DynamicArray() { delete[] array_; }

  template <class T> int DynamicArray<T>::GetSize() const { return size_; }

  template <class T> bool DynamicArray<T>::IsEmpty() const { return size_ == 0; }

  template <class T> T DynamicArray<T>::Get(int index) const {
    if (index < 0 || index >= size_) {
      throw std::out_of_range("Index out of bounds.");
    }
    return array_[index];
  }

  template <class T> void DynamicArray<T>::Set(int index, T value) {
    if (index < 0 || index >= size_) {
      throw std::out_of_range("Index out of bounds.");
    }
    array_[index] = value;
  }

  template <class T> void DynamicArray<T>::Append(T value) {
    ResizeArray(size_ + 1);
    array_[size_++] = value;
  }

  template <class T> void DynamicArray<T>::InsertAt(int index, T value) {
    if (index < 0 || index >= size_) {
      throw std::out_of_range("Index out of bounds.");
    }
    ResizeArray(size_ + 1);
    for (int i = size_; i > index; --i) {
      array_[i] = array_[i - 1];
    }
    array_[index] = value;
    ++size_;
  }

  template <class T> void DynamicArray<T>::RemoveAt(int index) {
    if (index < 0 || index >= size_) {
      throw std::out_of_range("Index out of bounds.");
    }
    ResizeArray(size_ - 1);
    for (int i = index; i < size_ - 1; ++i) {
      array_[i] = array_[i + 1];
    }
    --size_;
  }

  template <class T> void DynamicArray<T>::ResizeArray(int new_size) {
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

  template <class T> void DynamicArray<T>::IncreaseCapacity() {
    int new_capacity = capacity_ * kGrowthFactor;
    capacity_ = new_capacity;
    T* new_array = new T[new_capacity];
    for (int i = 0; i < size_; ++i) {
      new_array[i] = array_[i];
    }
    delete[] array_;
    array_ = new_array;
  }

  template <class T> void DynamicArray<T>::DecreaseCapacity() {
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

template class ds::DynamicArray<int>;
template class ds::DynamicArray<float>;
template class ds::DynamicArray<double>;
template class ds::DynamicArray<std::string>;
