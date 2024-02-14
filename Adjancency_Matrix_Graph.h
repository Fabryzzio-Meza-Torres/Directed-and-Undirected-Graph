#include <iostream>
#include "Doubly_Linked_List.h"
#include <vector>
#include <queue>
#include <stack>
struct Node
{
    int id;
    int weight;
    Node(int id, int weight) : id(id), weight(weight){};
};

struct Edge
{
    Node start;
    Node end;
    Edge(Node start, Node end) : start(start), end(end){};
};

struct Graph
{
    vector<Node *> vertex;
    vector<Edge *> edges;
    Graph(vector<Node *> vertex, vector<Edge *> edges) : vertex(vertex), edges(edges){};
};

void BFS(const Graph &graph, int startId)
{
    vector<bool> visited(graph.vertex.size(), false);
    queue<int> q;
    q.push(startId);
    visited[startId] = true;

    while (!q.empty())
    {
        int currentId = q.front();
        q.pop();
        cout << currentId << " ";

        for (Edge *edge : graph.edges)
        {
            if (edge->start.id == currentId && !visited[edge->end.id])
            {
                q.push(edge->end.id);
                visited[edge->end.id] = true;
            }
            else if (edge->end.id == currentId && !visited[edge->start.id])
            {
                q.push(edge->start.id);
                visited[edge->start.id] = true;
            }
        }
    }
}

void DFSHelper(const Graph &graph, int currentId, vector<bool> &visited)
{
    visited[currentId] = true;
    cout << currentId << " ";

    for (Edge *edge : graph.edges)
    {
        if (edge->start.id == currentId && !visited[edge->end.id])
        {
            DFSHelper(graph, edge->end.id, visited);
        }
        else if (edge->end.id == currentId && !visited[edge->start.id])
        {
            DFSHelper(graph, edge->start.id, visited);
        }
    }
}

void DFS(const Graph &graph, int startId)
{
    vector<bool> visited(graph.vertex.size(), false);
    DFSHelper(graph, startId, visited);
}
