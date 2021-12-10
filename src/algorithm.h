#pragma once

#include "graph.h"
#include "node.h"
#include <map>

class Algorithm {
  public:
    void BFS(Graph& g);

    void BFS(Graph& g, int v);

    vector<int> Dijkstra(Graph & g, Node start, Node end);
  private:
    enum label{
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

    std::map<int, label> nodeLabel_;
    std::map<std::pair<int, int>, label> edgeLabel_;
};