#pragma once

#include "graph.h"
#include "node.h"
#include <map>

class Algorithm {
  public:
    void BFS(Graph& g);

    void BFS(Graph& g, int v);

    vector<Node> Dijkstra(Graph & g, Node & start, Node & end);
  private:
    enum label{
      UNEXPLORED,
      VISITED,
      DISCOVERY,
      CROSS
    };

    struct NodeDist {
      Node node;
      int dist; 

      bool operator()(NodeDist nd1, NodeDist nd2)
      {
        return nd1.dist < nd2.dist;
      }
    };

    std::map<int, label> nodeLabel_;
    std::map<std::pair<int, int>, label> edgeLabel_;
};