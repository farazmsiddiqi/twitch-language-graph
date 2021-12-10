#include <queue>
#include <vector>
#include <map>
#include <list>

#include "graph.h"

class BFS {

    int vertices;
    std::list<int> * adjacencyList;

    bool * hasVisited;

    public:
        BFS(int numVert);

        void addEdge(int start, int end);
};