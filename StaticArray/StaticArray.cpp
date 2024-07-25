#pragma once 

template <typename T, size_t size>
class StaticArray {
public:
    T& at(size_t index) {
        return array[index];
    }

private:
    T array[size];
};
