#include "../cs225/catch/catch.hpp"

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

// why is #include "../src/node.h" throwing a linker command????
// #include "../src/node.cpp"

//SOLUTION: GENERATE THE .o FILE BY HAND: https://www.linuxtopia.org/online_books/an_introduction_to_gcc/gccintro_13.html
#include "../src/node.h"
#include "../src/graph.h"
#include "../src/algorithm.h"


TEST_CASE("Test Kosaraju-Sharir", "[weight=1][part=1][valgrind]") {

    Graph graph = Graph("data/test_data/SCC_features.csv", "data/test_data/SCC_edges.csv");

    Algorithm algo;

    int tester = algo.kosaraju_sharir(graph);

    REQUIRE(tester == 3);
}


TEST_CASE("Test on large strongly connected component, Kosaraju-Sharir", "[weight=1][part=1][valgrind]") {

    Graph graph = Graph("data/test_data/test_large_features.csv", "data/test_data/test_large_edges.csv");

    Algorithm algo;

    int tester = algo.kosaraju_sharir(graph);

    REQUIRE(tester == 17);
}
