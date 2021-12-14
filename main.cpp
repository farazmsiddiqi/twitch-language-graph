#include <iostream>

//SOLUTION: GENERATE THE .o FILE BY HAND, 
//and add it to makefile: https://www.linuxtopia.org/online_books/an_introduction_to_gcc/gccintro_13.html
#include "src/graph.h"
#include "src/node.h"
#include "src/algorithm.h"

using std::cout;
using std::endl;

int main() {

  Graph g = Graph("data/real_data/large_twitch_features.csv", "data/real_data/large_twitch_edges.csv", "FI");

  //Graph g = Graph("data/test_data/test_features.csv", "data/test_data/test_edges.csv", "EN");
  Algorithm algo;

  int largest_FI_community = algo.kosaraju_sharir(g);

  //g.print_adj_list();

  std::cout << "largest FI community: " << largest_FI_community << std::endl;
  return 0;
}
