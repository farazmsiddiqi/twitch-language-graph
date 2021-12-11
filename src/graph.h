#pragma once

#include "node.h"
#include <vector>
#include <fstream>
#include <iostream>
#include <sstream>
#include <unordered_map>
#include <string>

using std::string;
using std::vector;
using std::pair;
using std::unordered_map;

/**
 * This class will be used to hold a Graph's data.
 * 
 **/


class Graph {
    
    public:

        Graph(string features_file, string edges_file);

        struct Edge {
            Node src;
            Node dest;
            double weight;

            Edge() {}
            
            Edge(Node s, Node d, double w) {
                src = s;
                dest = d;
                weight = w;
            }

            bool operator()(Edge e1, Edge e2)
            {
                return e1.weight > e2.weight;
            }
        };

        bool makefile_test() {
            return true;
        }

        // key: nodeid1 value: 23_nodeid2

        /**
         * print out the adjacency list to console. 
         */
        void print_adj_list();
       
        bool has_node(int nodeID);

        unordered_map< int, Node > get_data_map();
        unordered_map< int, unordered_map< int, Edge> > get_adj_list() const;
    private:
        unordered_map< int, Node > data_map;
        
        unordered_map< int, unordered_map< int, Edge> > adj_list;

};
