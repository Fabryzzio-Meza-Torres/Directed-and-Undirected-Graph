#include <iostream>
#include <vector>
#include "Doubly_Linked_List.h"
#include "Undirected_Graph.h"
#include "Directed_Graph.h"
#include "Adjancency_Matrix_Graph.h"
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

    cout << endl;
    cout << endl
         << "Adjancency_Matrix_Graph" << endl;
    Node node1(0, 0);
    Node node2(1, 0);
    Node node3(2, 0);
    Node node4(3, 0);

    Edge edge1(node1, node2);
    Edge edge2(node2, node3);
    Edge edge3(node3, node4);
    Edge edge4(node4, node1);

    vector<Node *> vertices = {&node1, &node2, &node3, &node4};
    vector<Edge *> edges = {&edge1, &edge2, &edge3, &edge4};

    Graph graph(vertices, edges);

    cout << "BFS starting from vertex 0: ";
    BFS(graph, 0);
    cout << endl;

    cout << "DFS  starting from vertex 0: ";
    DFS(graph, 0);
    cout << endl;

    return 0;
}