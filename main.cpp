#include <iostream>

//SOLUTION: GENERATE THE .o FILE BY HAND, 
//and add it to makefile: https://www.linuxtopia.org/online_books/an_introduction_to_gcc/gccintro_13.html
#include "src/graph.h"
#include "src/node.h"
#include "src/algorithm.h"

using std::cout;
using std::endl;

int main() {

  std::string language = "FR";
  Graph g = Graph("data/real_data/large_twitch_features.csv", "data/real_data/large_twitch_edges.csv", language);

  Algorithm algo;

  int largest_lang_community = algo.kosaraju_sharir(g);

  std::cout << "largest " << language << " community: " << largest_lang_community << std::endl;
  return 0;
}
