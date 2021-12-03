#include "BFS.h"

BFS::BFS(int numVert) {
    vertices = numVert;
    adjacencyList = new list<int>[vertices];


}

void BFS::addEdge(int start, int end) {
    adjacencyList[start].push_back(end);
    adjacencyList[end].push_back(start);



}

void BFS::BFS(int startValue) {


}

//did basic implentationt o be later augmented using https://www.programiz.com/dsa/graph-bfs as influence