// 25 Construct a minimal spanning tree of a graph
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// Structure to represent an edge
struct Edge
{
    int src, dest, weight;
};
// Structure to represent a subset for union-find
struct Subset
{
    int parent, rank;
};
// Comparator function to sort edges by weight
bool compareEdges(const Edge &e1, const Edge &e2)
{
    return e1.weight < e2.weight;
}
// Find operation for union-find
int find(Subset subsets[], int i)
{
    if (subsets[i].parent != i)
    {
        subsets[i].parent = find(subsets, subsets[i].parent);
    }
    return subsets[i].parent;
}
// Union operation for union-find
void unionSets(Subset subsets[], int x, int y)
{
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);
    if (subsets[xroot].rank < subsets[yroot].rank)
    {
        subsets[xroot].parent = yroot;
    }
    else if (subsets[xroot].rank > subsets[yroot].rank)
    {
        subsets[yroot].parent = xroot;
    }
    else
    {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}
// Function to construct minimal spanning tree using Kruskal's algorithm
void kruskalMST(vector<Edge> &edges, int V)
{
    vector<Edge> MST;                               // Stores the edges of MST
    sort(edges.begin(), edges.end(), compareEdges); // Sort edges by
                                                    // weight
    //  Allocate memory for subsets
    Subset *subsets = new Subset[V];
    for (int i = 0; i < V; ++i)
    {
        subsets[i].parent = i;
        subsets[i].rank = 0;
    }
    int edgeCount = 0;
    for (const Edge &edge : edges)
    {
        int x = find(subsets, edge.src);
        int y = find(subsets, edge.dest);
        // If including this edge does not form a cycle, add it to MST
        if (x != y)
        {
            MST.push_back(edge);
            unionSets(subsets, x, y);
            edgeCount++;
        }
        // Stop when MST has V-1 edges
        if (edgeCount == V - 1)
            break;
    }
    // Print MST
    cout << "Minimal Spanning Tree:" << endl;
    for (const Edge &edge : MST)
    {
        cout << edge.src << " -- " << edge.dest << " \tWeight: " << edge.weight << endl;
    }
    delete[] subsets; // Free memory
}
int main()
{
    int V = 4;                                                                      // Number of vertices
    vector<Edge> edges = {{0, 1, 10}, {0, 2, 6}, {0, 3, 5}, {1, 3, 15}, {2, 3, 4}}; // Example edges
    kruskalMST(edges, V);
    return 0;
}