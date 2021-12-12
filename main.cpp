#include <iostream>

//SOLUTION: GENERATE THE .o FILE BY HAND, 
//and add it to makefile: https://www.linuxtopia.org/online_books/an_introduction_to_gcc/gccintro_13.html
#include "src/graph.h"
#include "src/node.h"


int main() {
  
  Graph g = Graph("data/test_data/test_features.csv", "data/test_data/test_edges.csv", "EN");

  g.print_adj_list();


  return 0;
}
