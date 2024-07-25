#pragma once 
#include <initializer_list>
#include <stdexcept>
#include <iostream>

template <typename T>
class LinkedList {
public:
  template<typename E>
  class Node{
  public:
    E data;
    Node* next{};
  };

  LinkedList() : mSize{0}, head{nullptr} {
  }

  LinkedList(LinkedList & rhs) {
    if (rhs.head == nullptr) {
      throw std::invalid_argument("the list to be copied is empty");
    }
    this->head = new Node<T>;
    this->head->data = rhs.head->data;
    mSize += 1;
    auto rhsNext = rhs.head->next;
    auto current = this->head;
    while (rhsNext != nullptr) {
      current->next = new Node<T>;
      current->next->data = rhsNext->data;
      mSize += 1;
    } 
  }

  LinkedList(std::initializer_list<T>) {
    
  }

  ~LinkedList() {
    while (this->head != nullptr) {
      auto temp = this->head;
      this->head = this->head->next;
      delete temp;
    }
  }
  
  bool add(T dataToAdd) {
    if (this->head == nullptr) {
      this->head = new Node<T>;
      this->head->data = dataToAdd;
      mSize+= 1;
      return 1;
    }

    auto current = this->head;
    while (current->next != nullptr) {
      current = current->next; 
    }
    current->next = new Node<T>;
    current->next->data = dataToAdd;
    mSize += 1;
    return 1;
  }

  bool remove(T dataToRemove) {
    if (this->head == nullptr) {
      return 0;
    }
    
    // handel the case where the element is the first
    if (this->head->data == dataToRemove) {
      auto rm = this->head;
      this->head = this->head->next;
      delete rm;
      mSize--;
      return 1;
    }

    // handel the rest of the cases 
    auto current = this->head->next;
    auto prev = this->head;
    while (current->data != dataToRemove && current->next != nullptr) {
      prev = current;
      current = current->next;
    }
    if (current->data == dataToRemove) {
      auto rm = current;
      prev->next = current->next;
      delete rm;
      mSize--;
      return 1;
    }
    return 0;
  }

  size_t size() {
    return mSize;
  }

  T& operator[] (size_t index) {
    auto current {this->head};
    for (size_t i=0; i < index; ++i) {
      current = current->next;
    }
    return current->data;
  }
  
  bool print() {
    auto current = this->head;
    while (current != nullptr) {
      std::cout << current->data << '\n';
      current = current->next; 
    }
    return 1;
  }

private:
  size_t mSize;
  Node<T>* head;
};
