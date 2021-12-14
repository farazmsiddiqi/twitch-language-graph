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

    Graph graph = Graph("data/test_data/Dijkstra_features.csv", "data/test_data/Dijkstra_edges.csv");
    REQUIRE( graph.makefile_test() == true);
}

TEST_CASE("Test Dijkstra", "[weight=1][part=1][valgrind]") {

    Graph graph = Graph("data/test_data/Dijkstra_features.csv", "data/test_data/Dijkstra_edges.csv");

    Algorithm algo;

    Node node1 = graph.get_data_map()[0];
    Node node2 = graph.get_data_map()[2];

    vector<int> tester = algo.dijkstra(graph, node1, node2);

    
    REQUIRE(tester.size() == 3);
    REQUIRE(tester[0] == 2);
    REQUIRE(tester[1] == 3);
    REQUIRE(tester[2] == 0);
}

TEST_CASE("Test Dijkstra with no path", "[weight=1][part=1][valgrind]") {

    Graph graph = Graph("data/test_data/SCC_features.csv", "data/test_data/SCC_edges.csv");

    Algorithm algo;

    Node node1 = graph.get_data_map()[0];
    Node node2 = graph.get_data_map()[2];

    vector<int> tester = algo.dijkstra(graph, node1, node2);

    
    REQUIRE(tester.size() == 0);
}

TEST_CASE("Test large Dijkstra", "[weight=1][part=1][valgrind]") {

    Graph graph = Graph("data/test_data/test_large_features.csv", "data/test_data/test_large_edges.csv");

    Algorithm algo;

    Node node1 = graph.get_data_map()[3];
    Node node2 = graph.get_data_map()[16];

    vector<int> tester = algo.dijkstra(graph, node1, node2);

    REQUIRE(tester.size() == 7);
    REQUIRE(tester[0] == 16);
    REQUIRE(tester[1] == 12);
    REQUIRE(tester[2] == 14);
    REQUIRE(tester[3] == 1);
    REQUIRE(tester[4] == 4);
    REQUIRE(tester[5] == 5);
    REQUIRE(tester[6] == 3);
}
