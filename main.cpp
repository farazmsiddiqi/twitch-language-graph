#include <iostream>
// #include "src/node.cpp"
// #include "src/csv_reader.cpp"

//SOLUTION: GENERATE THE .o FILE BY HAND, 
//and add it to makefile: https://www.linuxtopia.org/online_books/an_introduction_to_gcc/gccintro_13.html
#include "src/node.h"
#include "src/csv_reader.h"
#include "src/graph.h"


int main() {
  std::cout << "THIS MESSAGE IS BEING PRINTED BY main.cpp" << std::endl;
  Node test_node;

  Graph("data/large_twitch_features.csv", "data/large_twitch_edges.csv");

  return 0;
}
