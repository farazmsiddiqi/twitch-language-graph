#pragma once

#include "graph.h"
#include "node.h"
#include <map>
#include <stack>
#include <vector>

class Algorithm {

  public:
    /**
     * <enter a description about what the fn does>
     * 
     * @param g <enter a description>
     * @param n <enter a description>
     * 
     * @return <enter a description>
     **/
    vector<int> bfs(Graph& g, Node& n);

    /**
     * <enter a description about what the fn does>
     * 
     * @param g <enter a description>
     * @param start <enter a description>
     * @param end <enter a description>
     * 
     * @return <enter a description>
     **/
    vector<int> dijkstra(Graph & g, Node start, Node end);

    /**
     * <enter a description about what the fn does>
     * 
     * @param g <enter a description>
     * 
     * @return <enter a description>
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
     * <enter a description about what the fn does>
     * 
     * @param g <enter a description>
     * @param v <enter a description>
     * @param vect <enter a description>
     * 
     * @return <enter a description>
     **/
    void bfs(Graph& g, int v, vector<int>& vect);

    /**
     * <enter a description about what the fn does>
     * 
     * @param g <enter a description>
     * @param n <enter a description>
     * @param visited <enter a description>
     * @param out <enter a description>
     * 
     * @return <enter a description>
     **/
    void dfs_from_start(Graph& g, int n, unordered_map<int, bool>& visited, vector<int>& out);

    /**
     * <enter a description about what the fn does>
     * 
     * @param g <enter a description>
     * @param n <enter a description>
     * @param visited <enter a description>
     * @param s <enter a description>
     * 
     * @return <enter a description>
     **/
    void fill_stack_scc_order(Graph& g, int n, unordered_map<int, bool>& visited, std::stack<int>& s);

    std::map<int, Label> node_label;

    std::map<std::pair<int, int>, Label> edge_label;
};