#ifndef GRAPH
#define GRAPH

#include <iostream>
#include <list>

using namespace std;

class Graph {
private:
    int V;
    list<int> *adj;
    void DFSUtil(int v, bool visited[]);
public:
    Graph(int V);
    void addEdge(int v, int w);
    void DFS(int v);

};


#endif
