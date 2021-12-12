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


TEST_CASE("Test BFS", "[weight=1][part=1][valgrind]") {

    Graph graph = Graph("data/test_data/Dijkstra_features.csv", "data/test_data/Dijkstra_edges.csv");

    Algorithm algo;

    vector<int> tester = algo.BFS(graph);

    REQUIRE(tester.size() == 4);
}


TEST_CASE("Test large BFS", "[weight=1][part=1][valgrind]") {

    Graph graph = Graph("data/test_data/test_large_features.csv", "data/test_data/test_large_edges.csv");

    Algorithm algo;


    vector<int> tester = algo.BFS(graph);

    REQUIRE(tester.size() == 17);
    REQUIRE(tester[0] == 0);
    REQUIRE(tester[1] == 15);
    REQUIRE(tester[2] == 13);
    REQUIRE(tester[3] == 4);
    REQUIRE(tester[4] == 14);
    REQUIRE(tester[5] == 12);
    REQUIRE(tester[6] == 10);
    REQUIRE(tester[7] == 2);
    REQUIRE(tester[8] == 1);
    REQUIRE(tester[9] == 5);
    REQUIRE(tester[10] == 16);
    REQUIRE(tester[11] == 11);
    REQUIRE(tester[12] == 7);
    REQUIRE(tester[13] == 3);
    REQUIRE(tester[14] == 8);
    REQUIRE(tester[15] == 6);
    REQUIRE(tester[16] == 9);
    
}
