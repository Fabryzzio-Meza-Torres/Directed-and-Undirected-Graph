#include <iostream>
#include <vector>
#include "Doubly_Linked_List.h"
#include "Undirected_Graph.h"
#include "Directed_Graph.h"
using namespace std;

int main()
{
    cout << "Undirected_Graph: " << endl;
    Undirected_Graph<int> g(10);
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

    cout << endl
         << endl;
    cout << "Directed_Graph: " << endl;
    Directed_Graph<int> directed(10);
    directed.addEdge(2, 5);
    directed.addEdge(3, 8);
    directed.addEdge(4, 1);
    directed.addEdge(1, 9);
    directed.addEdge(9, 6);
    directed.addEdge(6, 1);
    directed.addEdge(0, 7);
    directed.addEdge(7, 4);
    directed.addEdge(8, 3);
    directed.addEdge(5, 2);
    directed.printAdjList();
    cout << "DFS: ";
    directed.DFS(0);
    cout << endl;
    cout << "BFS: ";
    directed.BFS(0);
}