#include <iostream>
#include <vector>
#include "Doubly_Linked_List.h"
using namespace std;

template <typename T>
class GraphAdjList
{
private:
    int vertices;
    DoublyLinkedList<T> *graph;

public:
    GraphAdjList(int V)
    {
        vertices = V;
        graph = new DoublyLinkedList<T>[V];
    }

    void addEdge(T x, T y)
    {
        if (x < vertices && y < vertices)
        {
            graph[x].push_back(y);
            graph[y].push_back(x);
        }
        else
        {
            cout << "Vertex index out of bounds" << endl;
        }
    }
    void printAdjList()
    {
        for (int i = 0; i < vertices; i++)
        {
            cout << "Vertex: " << i << "->";
            for (T j : graph[i])
            {
                cout << j << ",";
            }
            cout << endl;
        }
    }
};