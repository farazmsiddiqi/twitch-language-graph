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
        };

        bool makefile_test() {
            return true;
        }

        void print_adj_list();
       
        bool hasNode(int nodeID);
    private:
        unordered_map< int, Node > data_map;
        
        unordered_map< int, unordered_map< int, Edge> > adj_list;

};
