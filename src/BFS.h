#include <queue>
#include <vector>
#include <map>
#include <list>

#include "twitch_graphs.h"

class BFS {

    int vertices;
    list<int> * adjacencyList;

    bool * hasVisited;

    public:
        BFS(int numVert);

        void addEdge(int start, int end);

        void BFS (int startValue);

    




};