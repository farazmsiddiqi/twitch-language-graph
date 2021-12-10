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


TEST_CASE("graph class compiles using Dijkstra", "[weight=1][part=1][valgrind]") {

    Graph graph = Graph("data/Dijsktra_features.csv", "data/Dijsktra_edges.csv");
    graph.print_adj_list();
    REQUIRE( graph.makefile_test() == true);
}

TEST_CASE("Test Dijkstra", "[weight=1][part=1][valgrind]") {

    Graph graph = Graph("data/Dijsktra_features.csv", "data/Dijsktra_edges.csv");

    Algorithm algo;

    Node node1 = graph.getData_map()[0];
    Node node2 = graph.getData_map()[2];

    vector<int> tester = algo.Dijkstra(graph, node1, node2);

    
    REQUIRE(tester.size() == 3);
    REQUIRE(tester[0] == 2);
    REQUIRE(tester[1] == 3);
    REQUIRE(tester[2] == 0);
}

