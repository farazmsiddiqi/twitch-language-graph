#include "algorithm.h"
#include <stdexcept>
#include <queue>

vector<int> Algorithm::bfs(Graph& g, Node& n) {
  vector<int> out;
  for (auto n : g.get_data_map()) {
      node_label.insert(std::pair<int, Label>(n.first, UNEXPLORED));

      unordered_map<int, Graph::Edge> map = g.get_adj_list().at(n.first);
      for (auto e: map) {
          std::pair<int,int> edge(n.first, e.first);
          edge_label.insert(std::pair<std::pair<int,int>, Label>(edge, UNEXPLORED));
      }
  }

  bfs(g, n.get_numeric_id(), out);

  for (auto v: g.get_data_map()) {
      if (node_label[v.first] == UNEXPLORED) {
          bfs(g, v.first, out);
      }
  }

  return out;
}

void Algorithm::bfs(Graph& g, int v, vector<int>& out) {
    std::queue<int> q;
    node_label[v] = VISITED;
    out.push_back(v);
    q.push(v);

    while (!q.empty()) {
        v = q.front();
        q.pop();
        unordered_map<int, Graph::Edge> adj = g.get_adj_list().at(v);
        for (auto w : adj) {
            std::pair<int, int> edge(v, w.first);
            if (node_label[w.first] == UNEXPLORED) {
                edge_label[edge] = DISCOVERY;
                node_label[w.first] = VISITED;
                q.push(w.first);
                out.push_back(w.first); 
            } else if (edge_label[edge] == UNEXPLORED) {
                edge_label[edge] = CROSS;
            }
        }
    }
}

vector<int> Algorithm::dijkstra(Graph & g, Node start, Node end) {
    std::priority_queue<Graph::Edge, vector<Graph::Edge>, Graph::Edge> pq;
    std::unordered_map<int, Graph::Edge> map;
    std::unordered_map<int, Label> labels;

    std::unordered_map<int, std::unordered_map<int, Graph::Edge>> aList = g.get_adj_list();

    for (auto n: g.get_data_map()) {
        map.insert(std::pair<int, Graph::Edge>(n.second.get_numeric_id(), Graph::Edge(n.second, n.second, INT_MAX)));
        labels.insert(std::pair<int, Label>(n.second.get_numeric_id(), UNEXPLORED));
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

    if(curr.src.get_numeric_id() != end.get_numeric_id()) {
        std::cout << "Route not found" << std::endl;
        return vector<int>();
    }

    vector<int> out;
    while (curr.dest.get_numeric_id() != curr.src.get_numeric_id()) {
        out.push_back(curr.src.get_numeric_id());
        curr = map[curr.dest.get_numeric_id()];
    }
    out.push_back(curr.src.get_numeric_id());
    
    
    return out;
}

int Algorithm::kosaraju_sharir(Graph& g) {
    int biggest_scc = 0;
    std::vector<std::vector<int>> connected_components;
    std::stack<int> s;
    int numNodes = g.get_data_map().size();
    unordered_map<int, bool> visited;

    unordered_map<int, Node> nodes = g.get_data_map();
    for (auto i : nodes) {
        visited[i.first] = false;
    }

    for (auto i : nodes) {
        if (!visited[i.first]) {
            fill_stack_scc_order(g, i.first, visited, s);
        }
    }


    for (auto i : nodes) {
        visited[i.first] = false;
    }

    while (!s.empty()) {
        int node = s.top();
        s.pop();

        if (!visited[node]) {
            vector<int> new_scc;
            dfs_from_start(g, node, visited, new_scc);
            connected_components.push_back(new_scc);
            biggest_scc = std::max(biggest_scc, (int) new_scc.size());
        }
    }
    return biggest_scc;
}

void Algorithm::dfs_from_start(Graph& g, int n, unordered_map<int, bool>& visited, vector<int>& out) {
    visited[n] = true;
    out.push_back(n);

    unordered_map<int, unordered_map<int, Graph::Edge>> map = g.get_adj_list();
    for(auto edgeMap : map[n]) {
        if (!visited[edgeMap.first]) {
            dfs_from_start(g, edgeMap.first, visited, out);
        }
    }
}

void Algorithm::fill_stack_scc_order(Graph& g, int n, unordered_map<int, bool>& visited, std::stack<int>& s) {
    visited[n] = true;

    unordered_map<int, unordered_map<int, Graph::Edge>> map = g.get_adj_list();
    for (auto edgeMap : map[n]) {
        if (!visited[edgeMap.first]) {
            fill_stack_scc_order(g, edgeMap.first, visited, s);
        }
    }

    s.push(n);
}

