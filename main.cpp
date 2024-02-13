#include <iostream>
#include <vector>
#include "Doubly_Linked_List.h"
#include "GraphAdjList.h"
using namespace std;

int main()
{
    GraphAdjList<int> g(10);
    g.addEdge(6, 2);
    g.addEdge(2, 8);
    g.addEdge(3, 4);
    g.addEdge(1, 7);
    g.addEdge(7, 2);
    g.addEdge(1, 2);
    g.addEdge(3, 1);
    g.addEdge(9, 7);
    g.addEdge(0, 1);
    g.addEdge(5, 0);
    g.printAdjList();
    cout << "DFS: ";
    g.DFS(0);
    cout << endl;
    cout << "BFS: ";
    g.BFS(0);
}