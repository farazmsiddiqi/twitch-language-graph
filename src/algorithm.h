#pragma once

#include "graph.h"
#include "node.h"
#include <map>
#include <stack>
#include <vector>

class Algorithm {

  public:
    /**
     * Does a level order traversal of the Graph
     * 
     * @param g Graph to use the traversal on
     * @param n Node to start the traversal from
     * 
     * @return a vector of nodes in the order in which the bfs traverals.
     **/
    vector<int> bfs(Graph& g, Node& n);

    /**
     * Finds the shortest path between to node using weights
     * 
     * @param g Graph that is being used
     * @param start the node at which to start
     * @param end the node at which to end
     * 
     * @return the path taken from end to start.
     **/
    vector<int> dijkstra(Graph & g, Node start, Node end);

    /**
     * Finds the connected components and prints them to the console
     * 
     * @param g Graph to analyze.
     * 
     * @return the size of the biggest connnected component.
     **/
    int kosaraju_sharir(Graph& g);

  private:
    enum Label {
      UNEXPLORED,
      VISITED,
      DISCOVERY,
      CROSS
    };

    struct NodeDist {
      Node node;
      double dist;
      Node back; 
    };

    /**
     * Helper for the bfs.
     * 
     * @param g Graph to traverse
     * @param v node at which to start
     * @param vect vector that will be return in the main bfs function
     **/
    void bfs(Graph& g, int v, vector<int>& vect);

    /**
     * DFS traversal to help the kasuraju_sharir algo.
     * 
     * @param g Graph to traverse
     * @param n Node at which to start
     * @param visited a map of nodes to a boolean that indicated whether or not it was visited
     * @param out vector that will be returned in the main function.
     **/
    void dfs_from_start(Graph& g, int n, unordered_map<int, bool>& visited, vector<int>& out);

    /**
     * Fills the stack using DFS and post order addition to the stack
     * 
     * @param g Graph to traverse
     * @param n Node at which to start
     * @param visited a map of nodes to a boolean that indicated whether or not it was visited
     * @param s Stack to fill
     **/
    void fill_stack_scc_order(Graph& g, int n, unordered_map<int, bool>& visited, std::stack<int>& s);

    std::map<int, Label> node_label;

    std::map<std::pair<int, int>, Label> edge_label;
};