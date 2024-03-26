// 22 Construct a graph
#include <iostream>
#include <list>
#include <unordered_map>
using namespace std;
// Class representing a graph
class Graph
{
private:
    // Number of vertices
    int V;
    // Adjacency list representation
    unordered_map<int, list<int>> adjList;

public:
    // Constructor
    Graph(int vertices) : V(vertices) {}
    // Function to add an edge to the graph
    void addEdge(int src, int dest)
    {
        adjList[src].push_back(dest);
        adjList[dest].push_back(src); // For undirected graph
    }
    // Function to print the adjacency list
    void printAdjList()
    {
        for (auto &pair : adjList)
        {
            cout << "Vertex " << pair.first << " is connected to:";
            for (int neighbor : pair.second)
            {
                cout << " " << neighbor;
            }
            cout << endl;
        }
    }
};
int main()
{
    // Create a graph with 5 vertices
    Graph g(5);
    // Add edges
    g.addEdge(0, 1);
    g.addEdge(0, 4);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 3);
    g.addEdge(3, 4);
    // Print the adjacency list
    g.printAdjList();
    return 0;
}