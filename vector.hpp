#pragma once

#include <iostream>
#include <stdexcept>

template <typename T>

class Vector {
private:
  T *storage;
  size_t vect_size;
  size_t vect_capacity;

public:
  Vector() {
    vect_size = 0;
    vect_capacity = 8;
    storage = new T[vect_capacity];
  }

  Vector(size_t elements) {
    vect_size = 0;
    vect_capacity = elements;
    storage = new T[vect_capacity];
  }

  ~Vector() { delete[] storage; }

  int &operator[](size_t index) {
    if (index >= vect_size) {
      throw std::out_of_range("Index out of bounds\n");
    }
    return storage[index];
  }

  size_t size() const { return vect_size; }

  size_t capacity() const { return vect_capacity; }

  T at(size_t index) const { return storage[index]; }

  void resize(size_t elements) {
    if (elements >= vect_capacity) {
      vect_capacity = capacity();
      T *new_storage = new T[vect_capacity];
      for (size_t i = 0; i < vect_size; i++) {
        new_storage[i] = storage[i];
      }
      delete[] storage;
      storage = new_storage;
    }
  }

  void push_front(T data) {
    T temp = storage[0];
    int i = 0;
    if (vect_size == vect_capacity) {
      resize(vect_capacity * 2);
    }

    for (size_t i = vect_size; i > 0; i--) {
      storage[i] = storage[i - 1];
    }
    storage[0] = data;
    vect_size++;
  }

  void push_back(T data) {
    if (vect_size == vect_capacity) {
      resize(vect_capacity * 2);
    }
    storage[vect_size++] = data;
  }
};

template <typename T>
std::ostream &operator<<(std::ostream &os, const Vector<T> &vect) {
  os << "[";
  for (int i = 0; i < vect.size(); i++) {
    os << " " << vect.at(i) << " ";
  }
  os << "]";
  return os;
}
