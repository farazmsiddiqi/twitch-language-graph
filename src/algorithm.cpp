#include "algorithm.h"
#include <stdexcept>
#include <queue>

Algorithm::Algorithm(Graph& g) {
    graph_ = g;
}

int Algorithm::BFS(Node start, Node target) {
    if (!graph_.hasNode(start)) {
        throw std::invalid_argument("The start node is not in the graph");
    }

    if (!graph.hasNode(target)) {
        throw std::invalid_argument("The target node is not in the graph");
    }
    
    //queue for BFS
    std::queue<int> q;

    startID = start.get_numeric_id();
    q.push(startID);

    //map from nodeID to distance
    unordered_map<int, int> visited;

    //add first pair
    std::pair<int, int> startPair(startID, 0);
    visited.insert(startID);

    Node curr = 
    while (!q.empty()) {
        

    }

    
    return -1;
}
