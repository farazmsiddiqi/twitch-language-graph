#pragma once

#include "graph.h"
#include "node.h"


class Algorithm {
  public:
    Algorithm(Graph& g);

    int BFS(Node start, Node target);
  private:
    Graph& graph_;

};