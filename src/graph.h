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
 **/

class Graph {
    
    public:

        /**
         * Take a node attribute file (features_file) and a node relationship file (edges_file).
         * Build a graph represented by an adjacency list of nodes.
         * 
         * @param features_file a node attribute file to build nodes for the graph.
         * @param edges_file a file describing relationships between nodes.
         * 
         **/
        Graph(string features_file, string edges_file);

        /**
         * Take a node attribute file (features_file), node relationship file (edges_file),
         * and a language (lang). Build a graph represented by an adjacency list of nodes 
         * who only speak the specified language.
         * 
         * @param features_file a node attribute file to build nodes for the graph.
         * @param edges_file a file describing relationships between nodes.
         * @param lang determining what language every node (twitch streamer) in the graph speaks (ex: "EN").
         * 
         **/
        Graph(string features_file, string edges_file, string lang);

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

        /**
         * test to see if makefile recognizes graph class.
         * 
         * @return a boolean 'ping-pong' response.
         **/
        bool makefile_test() {
            return true;
        }

        /**
         * print out the adjacency list to console. 
         */
        void print_adj_list();

        /**
         * determine if a given nodeID has a node.
         * 
         * @return true if it has a node, false otherwise.
         **/
        bool has_node(int nodeID);

        unordered_map< int, Node > get_data_map();

        unordered_map< int, unordered_map< int, Graph::Edge> > get_adj_list();


    private:
        // allows us to filter for older accounts
        //const int MIN_LIFETIME = 2000;

        // Maps node_ids to Node objects.
        unordered_map< int, Node > data_map;
        
        // Adjacency list containing the graph.
        unordered_map< int, unordered_map< int, Edge> > adj_list;

};
