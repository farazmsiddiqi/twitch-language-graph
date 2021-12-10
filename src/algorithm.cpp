#include "algorithm.h"
#include <stdexcept>
#include <queue>


void Algorithm::BFS(Graph& g) {
  for (auto n : g.getData_map()) {
      nodeLabel_.insert(std::pair(n.first, UNEXPLORED));

      unordered_map<int, Graph::Edge> map = g.getAdj_list().at(n.first);
      for (auto e: map) {
          std::pair<int,int> edge(n.first, e.first);
          edgeLabel_.insert(std::pair<edge, UNEXPLORED));
      }
  }

  for (auto v: g.getData_map()) {
      if (nodeLabel_[v.first] == UNEXPLORED) {
          BFS(g, v.first);
      }
  }
}

void Algorithm::BFS(Graph& g, int v) {
    std::queue<int> q;
    nodeLabel_[v] = VISITED;
    q.push(v);

    while(!q.empty()) {
        v = q.front;
        q.pop;
        unordered_map<int, Graph::Edge> adj = g.getAdj_list().at(v);
        for (auto w : adj) {
            std::pair<int, int> edge(v, w.first);
            if (nodeLabel_[w.first] == UNEXPLORED) {
                edgeLabel_[edge] = DISCOVERY;
                nodeLabel_[w.first] = VISITED;
                q.push(w.first);
            } else if (edgeLabel_[edge] == UNEXPLORED) {
                edgeLabel_[edgeLabel_] == CROSS;
            }
        }
    }
}