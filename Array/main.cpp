#include <iostream>
#include "lib.hpp"

int main() {
  std::cout << "Welcome to CppPlayground" << std::endl;
  asl::Array<int, 10> arr;
  for (int i =0; i< 10; ++i) {
    arr[i] = i;
  }
  asl::Array<int, 10> array{arr};
  for (int i=9; i >=0; --i) {
    std::cout << arr[i] << '\t' <<  array[i] << '\n';
  }
  return 0;
}
