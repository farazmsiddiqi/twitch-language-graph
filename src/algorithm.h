#pragma once

#include "graph.h"
#include "node.h"
#include <map>
#include <stack>
#include <vector>

class Algorithm {

  public:
    /**
     * This function returns a vector of integers in the order they were traversed from the source node . 
     * 
     * @param g <The Graph reference that is a CSV file that includes features of a twtich user, as well as the largest edges between two nodes.>
     * @param n <The source node "n" to begin traversing from.>
     * 
     * @return <A vector or integers in the order they were traversed in from the source node.>
     **/
    vector<int> bfs(Graph& g, Node& n);

    /**
     * <This function returns a vector of integers in the reverse order they were traversed from the end node to the start node.>
     * 
     * @param g <The Graph reference that is a CSV file that includes features of a twtich user, as well as the largest edges between two nodes.>
     * @param start <The start node to begin traversing from.>
     * @param end <The node to end traversing at.>
     * 
     * @return <Returns a vector of integers in the reverse order they were traversed from the end node to the start node.>
     **/
    vector<int> dijkstra(Graph & g, Node start, Node end);

    /**
     * <This function returns the size of the largest strongly connected component in the dataset.>
     * 
     * @param g <The Graph reference that is a CSV file that includes features of a twtich user, as well as the largest edges between two nodes.>
     * 
     * @return <The size of the largest strongly connected component>
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
     * <This is a helper for the primary BFS algorithm above, as it runs a BFS on every node.
     *  The main BFS algorithm that returns the vector of integers calls the helper.>
     * 
     * @param g <The Graph reference that is a CSV file that includes features of a twtich user, as well as the largest edges between two nodes.>
     * @param v <The index used for the labeler nodes and the output vector.>
     * @param vect <The output vector that we push the BFS'ed nodes to.>
     * 
     **/
    void bfs(Graph& g, int v, vector<int>& vect);

    /**
     * <This is a helper for the Dijkstras method that traverses through an adjacency list and recursivley checks which nodes have not been visited.>
     * 
     * @param g <The Graph reference that is a CSV file that includes features of a twtich user, as well as the largest edges between two nodes.>
     * @param n <The index to use for the visited nodes and for the edge map>
     * @param visited <A boolean vector of that stores visited nodes.>
     * @param out <The vector that stores the indices of the stored nodes.>
     * 
     **/
    void dfs_from_start(Graph& g, int n, unordered_map<int, bool>& visited, vector<int>& out);

    /**
     * <This method is a helper for our SCC function that populates a stack with the largets storngly connected component in the dataset.>
     * 
     * @param g <The Graph reference that is a CSV file that includes features of a twtich user, as well as the largest edges between two nodes.>
     * @param n <The index for the visited vector of nodes, and the map.>
     * @param visited <A boolean vector of that stores visited nodes.>
     * @param s <The stack to store the nodes in the SCC.>
     * 
     **/
    void fill_stack_scc_order(Graph& g, int n, unordered_map<int, bool>& visited, std::stack<int>& s);

    std::map<int, Label> node_label;

    std::map<std::pair<int, int>, Label> edge_label;
};