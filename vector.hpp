#pragma once

#include <memory>

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

    ~Vector() { delete storage; }

    size_t size() { return vect_size; }
    size_t capacity() { return vect_capacity; }
    void resize(size_t elements) {
        vect_capacity = capacity();
        T *new_storage = new T[vect_capacity];
        for (size_t i = 0; i < vect_size; i++) {
            new_storage[i] = storage[i];
        }
        delete storage;
        storage = new_storage;
    }
};
