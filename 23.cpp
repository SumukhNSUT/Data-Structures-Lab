#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;

// Class representing a graph
class Graph
{
private:
    int V;                                   // Number of vertices
    unordered_map<int, vector<int>> adjList; // Adjacency list
public:
    // Constructor
    Graph(int vertices) : V(vertices) {}

    // Function to add an edge to the graph
    void addEdge(int src, int dest)
    {
        adjList[src].push_back(dest);
        adjList[dest].push_back(src); // For undirected graph
    }

    // Function to calculate the distance between two vertices using BFS
    int distanceBetweenVertices(int start, int end)
    {
        if (start == end)
            return 0;

        queue<int> q;
        unordered_map<int, bool> visited;
        unordered_map<int, int> distance;

        // Initialize distances and visited map
        for (auto &pair : adjList)
        {
            visited[pair.first] = false;
            distance[pair.first] = -1; // -1 indicates unreachable
        }

        q.push(start);
        visited[start] = true;
        distance[start] = 0;

        while (!q.empty())
        {
            int current = q.front();
            q.pop();
            for (int neighbor : adjList[current])
            {
                if (!visited[neighbor])
                {
                    q.push(neighbor);
                    visited[neighbor] = true;
                    distance[neighbor] = distance[current] + 1;
                    if (neighbor == end)
                    {
                        // Found the end vertex, return its distance from start
                        return distance[neighbor];
                    }
                }
            }
        }

        // End vertex is unreachable from the start
        return -1;
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

    // Calculate distance between vertices
    int distance = g.distanceBetweenVertices(0, 3);

    if (distance != -1)
    {
        cout << "Distance between vertices 0 and 3: " << distance << endl;
    }
    else
    {
        cout << "Vertices are not connected or one of them doesn't exist." << endl;
    }

    return 0;
}
