#include <iostream>
#include "Doubly_Linked_List.h"
#include <vector>
#include <queue>
using namespace std;

template <typename T>
class Undirected_Graph
{
private:
    int vertices;
    DoublyLinkedList<T> *graph;

public:
    Undirected_Graph(int V)
    {
        vertices = V;
        graph = new DoublyLinkedList<T>[V];
    }

    ~Undirected_Graph()
    {
        delete[] graph;
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

    void DFSHelper(int v, vector<bool> &visited)
    {
        visited[v] = true;
        cout << v << " ";
        for (T i : graph[v])
        {
            if (!visited[i])
            {
                DFSHelper(i, visited);
            }
        }
    }

    void DFS(int startVertex)
    {
        vector<bool> visited(vertices, false);
        DFSHelper(startVertex, visited);
    }

    void BFS(int startVertex)
    {
        vector<bool> visited(vertices, false);
        queue<T> q;
        visited[startVertex] = true;
        q.push(startVertex);

        while (!q.empty())
        {
            T current = q.front();
            q.pop();
            cout << current << " ";

            for (T i : graph[current])
            {
                if (!visited[i])
                {
                    visited[i] = true;
                    q.push(i);
                }
            }
        }
    }

    void clear()
    {
        delete[] graph;
    }
};