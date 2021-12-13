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

TEST_CASE("Twitch::Makefile makefile works", "[weight=1][part=1][valgrind]") {
    // tests if the test_file is recognized by makefile.
    REQUIRE( 10 == 10 );
}

TEST_CASE("Twitch::Makefile node class compiles", "[weight=1][part=1][valgrind]") {

    Node test_node = Node(0,0, "EN");

    REQUIRE( test_node.makefile_test_func() == true );
}

TEST_CASE("Twitch::Makefile graph class compiles", "[weight=1][part=1][valgrind]") {

    Graph graph = Graph("data/test_data/test_features.csv", "data/test_data/test_edges.csv");

    REQUIRE( graph.makefile_test() == true);
}

TEST_CASE("Twitch::adj_list read correctly", "[weight=1][part=1][valgrind]") {

    Graph graph = Graph("data/test_data/test_features.csv", "data/test_data/test_edges.csv");

    vector<int> correct_src_keys = {0, 1, 2, 3};
    vector< vector<int> > correct_dest_keys = 
    { 
        { 3, 1 }, 
        { 3, 2, 0 }, 
        { 3, 1 }, 
        { 1, 0, 2 } 
    };

    vector<int> src_keys;
    vector< vector<int> > dest_keys;
    unordered_map< int, unordered_map< int, Graph::Edge> >::iterator test_it;
    unordered_map< int, unordered_map< int, Graph::Edge> > adjacency_list = graph.get_adj_list();

    // loads the src_keys and dest_keys
    for (test_it = adjacency_list.begin(); test_it != adjacency_list.end(); ++test_it) {
        src_keys.push_back(test_it->first);
        unordered_map< int, Graph::Edge> map = test_it->second;

        vector<int> dests_for_one_src;
        unordered_map< int, Graph::Edge>::iterator test_it2;
        for (test_it2 = map.begin(); test_it2 != map.end(); ++test_it2) {
            dests_for_one_src.push_back(test_it2->first);
        }
        dest_keys.push_back(dests_for_one_src);
        dests_for_one_src.clear();
    }

    // check them now
    REQUIRE( correct_src_keys == src_keys );
    REQUIRE( correct_dest_keys == dest_keys );

    //REQUIRE( graph.print_adj_list() == correct_node_keys);
}

