#include "../cs225/catch/catch.hpp"

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#include "../cs225/PNG.h"
#include "../cs225/HSLAPixel.h"

// why is #include "../src/node.h" throwing a linker command????
// #include "../src/node.cpp"

//SOLUTION: GENERATE THE .o FILE BY HAND: https://www.linuxtopia.org/online_books/an_introduction_to_gcc/gccintro_13.html
#include "../src/node.h"
#include "../src/graph.h"

using namespace cs225;

TEST_CASE("Twitch::Makefile makefile works", "[weight=1][part=1][valgrind]") {

    std::cout << "\n if this message is showing, our makefile works!" << std::endl;

    REQUIRE( 10 == 10 );
}

TEST_CASE("Twitch::Makefile node class compiles", "[weight=1][part=1][valgrind]") {

    Node test_node;

    REQUIRE( test_node.makefile_test_func() == true );
}

TEST_CASE("Twitch::Makefile graph class compiles", "[weight=1][part=1][valgrind]") {

    Graph graph = Graph("data/large_twitch_features.csv", "data/large_twitch_edges.csv");

    REQUIRE( graph.makefile_test() == true);
}