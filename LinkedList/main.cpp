#include <iostream>
#include "LinkedList.hpp"

int main() {
  std::cout << "Linked-List" << std::endl;
  LinkedList<int> list;
  for(size_t i = 0; i<1000; ++i) {
    list.add(i);
  }
  // list.print();
  for(size_t i = 0; i<100; ++i) {
    std::cout << "removed : " << list[0] << '\n' ;
    list.remove(list[0]);
  }

  for(size_t i = 0; i<list.size(); ++i) {
    std::cout << list[i] << '\n';
  }
  std::cout << "Size = " << list.size() << std::endl;
  return 0;
}
