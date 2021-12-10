#include "BFS.h"

BFS::BFS(int numVert) {
    vertices = numVert;
    adjacencyList = new std::list<int>[vertices];
}

void BFS::addEdge(int start, int end) {
    adjacencyList[start].push_back(end);
    adjacencyList[end].push_back(start);
}

//did basic implentation to be later augmented using https://www.programiz.com/dsa/graph-bfs as influence