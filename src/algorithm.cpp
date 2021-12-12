#include "algorithm.h"
#include <stdexcept>
#include <queue>

vector<int> Algorithm::BFS(Graph& g, Node& n) {
  vector<int> out;
  for (auto n : g.get_data_map()) {
      nodeLabel_.insert(std::pair<int, label>(n.first, UNEXPLORED));

      unordered_map<int, Graph::Edge> map = g.get_adj_list().at(n.first);
      for (auto e: map) {
          std::pair<int,int> edge(n.first, e.first);
          edgeLabel_.insert(std::pair<std::pair<int,int>, label>(edge, UNEXPLORED));
      }
  }

  BFS(g, n.get_numeric_id(), out);

  for (auto v: g.get_data_map()) {
      if (nodeLabel_[v.first] == UNEXPLORED) {
          BFS(g, v.first, out);
      }
  }

  return out;
}

void Algorithm::BFS(Graph& g, int v, vector<int>& out) {
    std::queue<int> q;
    nodeLabel_[v] = VISITED;
    out.push_back(v);
    q.push(v);

    while (!q.empty()) {
        v = q.front();
        q.pop();
        unordered_map<int, Graph::Edge> adj = g.get_adj_list().at(v);
        for (auto w : adj) {
            std::pair<int, int> edge(v, w.first);
            if (nodeLabel_[w.first] == UNEXPLORED) {
                edgeLabel_[edge] = DISCOVERY;
                nodeLabel_[w.first] = VISITED;
                q.push(w.first);
                out.push_back(w.first); 
            } else if (edgeLabel_[edge] == UNEXPLORED) {
                edgeLabel_[edge] = CROSS;
            }
        }
    }
}

vector<int> Algorithm::Dijkstra(Graph & g, Node start, Node end) {
    std::priority_queue<Graph::Edge, vector<Graph::Edge>, Graph::Edge> pq;
    std::unordered_map<int, Graph::Edge> map;
    std::unordered_map<int, label> labels;

    std::unordered_map<int, std::unordered_map<int, Graph::Edge>> aList = g.get_adj_list();

    for (auto n: g.get_data_map()) {
        map.insert(std::pair<int, Graph::Edge>(n.second.get_numeric_id(), Graph::Edge(n.second, n.second, INT_MAX)));
        labels.insert(std::pair<int, label>(n.second.get_numeric_id(), UNEXPLORED));
    }
    Graph::Edge startEdge(start, start, 0);
    map[start.get_numeric_id()] = startEdge;
    pq.push(startEdge);

    Graph::Edge curr;
    
    while (!pq.empty()) {
        curr = pq.top();
        pq.pop();
        int currNode = curr.src.get_numeric_id();

        labels[currNode] = VISITED;

        if (currNode == end.get_numeric_id()) {
            break;
        }

        std::unordered_map<int, Graph::Edge> edgeList = aList[currNode];
        for(auto e : edgeList) {
            Graph::Edge & edge = e.second;
            Node next = edge.dest;

            if (labels[next.get_numeric_id()] == UNEXPLORED) {
                double newDist = edge.weight + map[currNode].weight;
                if (newDist < map[next.get_numeric_id()].weight) {
                    Graph::Edge newEdge(Node(next.get_numeric_id(), 0, ""), Node(currNode, 0, ""), newDist);
                    map[next.get_numeric_id()] = newEdge;
                }

                pq.push(map[next.get_numeric_id()]);
            }
        }

        
    }

    vector<int> out;
    while (curr.dest.get_numeric_id() != curr.src.get_numeric_id()) {
        out.push_back(curr.src.get_numeric_id());
        curr = map[curr.dest.get_numeric_id()];
    }
    out.push_back(curr.src.get_numeric_id());
    
    
    return out;
}

void Algorithm::SCC(Graph& g) { }