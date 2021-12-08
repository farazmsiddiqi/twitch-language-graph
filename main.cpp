#include <iostream>

//SOLUTION: GENERATE THE .o FILE BY HAND, 
//and add it to makefile: https://www.linuxtopia.org/online_books/an_introduction_to_gcc/gccintro_13.html
#include "src/graph.h"
#include "src/node.h"


int main() {
  std::cout << "THIS MESSAGE IS BEING PRINTED BY the file main.cpp" << std::endl;
  //Node test_node = Node(0,0,"EN");

  Graph g = Graph("data/test_features.csv", "data/test_edges.csv");
  std::cout << "THIS MESSAGE IS AFTER CALLING GRAPH CTOR" << std::endl;


  return 0;
}
