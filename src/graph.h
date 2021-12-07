#pragma once

#include "node.h"
#include <vector>
#include <utility>
#include <fstream>
#include <iostream>
#include <sstream>
#include <map>

using std::string;
using std::vector;
using std::pair;
using std::map;

/**
 * This class will be used to hold a Graph's data.
 * 
 **/


class Graph {
    
    public:
        Graph(string features_file, string edges_file);

        bool makefile_test() {
            return true;
        }
       
    private:
        // pair(destination node, weight)
        //map< Node, vector<pair<Node, double> > > adj_list;

        vector< vector< pair< Node, double > > > adj_list;

};


