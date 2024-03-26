// 24 Calculate the distances between every pairs of vertices in a graph
#include <iostream>
#include <vector>
#include <limits>
using namespace std;
#define INF numeric_limits<int>::max()
// Function to calculate distances between all pairs of vertices
void floydWarshall(vector<vector<int>> &graph)
{
    int V = graph.size();
    // Initialize distances matrix
    vector<vector<int>> dist(V, vector<int>(V));
    // Initialize distances with graph values
    for (int i = 0; i < V; ++i)
    {
        for (int j = 0; j < V; ++j)
        {
            dist[i][j] = graph[i][j];
        }
    }
    // Update distances using intermediate vertices
    for (int k = 0; k < V; ++k)
    {
        for (int i = 0; i < V; ++i)
        {
            for (int j = 0; j < V; ++j)
            {
                // If vertex k is on the shortest path from i to j, then update dist[i][j]
                if (dist[i][k] != INF && dist[k][j] != INF && dist[i][k] + dist[k][j] < dist[i][j])
                {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
    // Print distances
    cout << "Distances between all pairs of vertices:" << endl;
    for (int i = 0; i < V; ++i)
    {
        for (int j = 0; j < V; ++j)
        {
            if (dist[i][j] == INF)
            {
                cout << "INF\t";
            }
            else
            {
                cout << dist[i][j] << "\t";
            }
        }
        cout << endl;
    }
}
int main()
{
    // Example graph represented as adjacency matrix
    vector<vector<int>> graph = {
        {0, 5, INF, 10},
        {INF, 0, 3, INF},
        {INF, INF, 0, 1},
        {INF, INF, INF, 0}};
    floydWarshall(graph);
    return 0;
}