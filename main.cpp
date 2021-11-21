#include <iostream>
#include "src/node.cpp"


int main() {
  std::cout << "THIS MESSAGE IS BEING PRINTED BY main.cpp" << std::endl;

  Node test_node;

  test_node.makefile_test_func();

  return 0;
}
