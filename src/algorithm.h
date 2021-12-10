#pragma once

#include "graph.h"
#include "node.h"
#include <map>

class Algorithm {
  public:
    void BFS(Graph& g);

    void BFS(Graph& g, int v);
  private:
    enum label{
      UNEXPLORED,
      VISITED,
      DISCOVERY,
      CROSS
    };

    std::map<int, label> nodeLabel_;
    std::map<std::pair<int, int>, label> edgeLabel_;

};