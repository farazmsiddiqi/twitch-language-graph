#include <iostream>

//SOLUTION: GENERATE THE .o FILE BY HAND, 
//and add it to makefile: https://www.linuxtopia.org/online_books/an_introduction_to_gcc/gccintro_13.html
#include "src/graph.h"
#include "src/node.h"
#include "src/algorithm.h"

using std::cout;
using std::endl;

int main() {
  unordered_map<string, int> result;

  result["CS"] = 0;
  result["DA"] = 0;
  result["FI"] = 0;
  result["HU"] = 0;
  result["IT"] = 0;
  result["NO"] = 0;
  result["PL"] = 0;


  for (auto pair : result) {
    Graph g = Graph("data/real_data/large_twitch_features.csv", "data/real_data/large_twitch_edges.csv", pair.first);
    
    Algorithm algo;

    result[pair.first] = algo.kosaraju_sharir(g);
  }

  //Graph g = Graph("data/test_data/test_features.csv", "data/test_data/test_edges.csv", "EN");


  //g.print_adj_list();

  for (auto pair : result) {
    std::cout << "largest_" << pair.first << "_community: "  << pair.second << std::endl;
  }

  return 0;
}
