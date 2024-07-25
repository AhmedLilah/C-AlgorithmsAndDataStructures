#pragma once
#include <initializer_list>
#include <stdexcept>

namespace asl{
  template <typename T, size_t size>
  class Array {
  public:
    Array() = default;
    Array(std::initializer_list<T>);
    Array(Array &);
    ~Array() = default;
    T& operator[] (size_t index);
    T& at(size_t index);
    size_t len();
  private:
    T array[size];
    size_t mSize = size;
  };
}

namespace asl {
  template <typename T, size_t size>
  Array<T, size>::Array(std::initializer_list<T> list) {
    if (list.size() >= this->len()) {
      throw std::out_of_range("the input list is bigger than the array size.");  
    }
    for (size_t i=0; i < list.size(); ++i) {
      this->array[i] = std::data(list)[i];
    }
  }
  
  template<typename T, size_t size>
  Array<T, size>::Array(Array & rhs) {
    if (rhs.len() > this->len()) {
      throw std::out_of_range("the copied array size is bigger than the arry size");
    }
    for (size_t i=0; i< rhs.len(); ++i) {
      array[i] = rhs[i];   
    }
  }
  
  template<typename T, size_t size>
  T& Array<T, size>::operator[] (size_t index) {
  return this->array[index];
  }

  template<typename T, size_t size>
  T& Array<T, size>::at(size_t index) {
    if (index >= size) {
      throw std::out_of_range("the array index is out of bound");
    }
    return this->array[index];
  }
  
  template<typename T, size_t size>
  size_t Array<T, size>::len() {
    return mSize; 
  }
}
