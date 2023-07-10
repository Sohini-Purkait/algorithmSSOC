#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

typedef pair<int, int> pii;

// Function to add an edge to the graph
void addEdge(vector<vector<pii>>& graph, int u, int v, int weight)
{
    graph[u].push_back(make_pair(v, weight));
    graph[v].push_back(make_pair(u, weight));
}

// Prim's algorithm function
vector<pii> primMST(vector<vector<pii>>& graph, int startVertex)
{
    int V = graph.size();

    // Priority queue to store vertices
    // that are candidates for MST
    priority_queue<pii, vector<pii>, greater<pii>> pq;

    vector<int> key(V, INT_MAX); // Key values to pick minimum weight edge
    vector<int> parent(V, -1);   // Array to store constructed MST
    vector<bool> inMST(V, false); // To represent whether a vertex is in MST or not

    // Insert startVertex into pq and initialize its key as 0
    pq.push(make_pair(0, startVertex));
    key[startVertex] = 0;

    // Prim's algorithm
    while (!pq.empty())
    {
        int u = pq.top().second; // Extract minimum key vertex from pq
        pq.pop();

        inMST[u] = true; // Include vertex in MST

        // Update key values of adjacent vertices
        for (auto& neighbor : graph[u])
        {
            int v = neighbor.first;
            int weight = neighbor.second;

            if (inMST[v] == false && key[v] > weight)
            {
                // Update the key value and insert it into pq
                key[v] = weight;
                pq.push(make_pair(key[v], v));
                parent[v] = u;
            }
        }
    }

    // Store the MST edges
    vector<pii> mst;
    for (int i = 1; i < V; ++i)
        mst.push_back(make_pair(parent[i], i));

    return mst;
}

// Function to print the MST edges and their weights
void printMST(const vector<pii>& mst)
{
    int totalWeight = 0;

    cout << "Minimum Spanning Tree:" << endl;
    for (const auto& edge : mst)
    {
        cout << edge.first << " - " << edge.second << endl;
        totalWeight += edge.second;
    }

    cout << "Total Weight: " << totalWeight << endl;
}

int main()
{
    int V, E;
    cout << "Enter the number of vertices: ";
    cin >> V;
    cout << "Enter the number of edges: ";
    cin >> E;

    vector<vector<pii>> graph(V);

    cout << "Enter the edges (source, destination, weight):" << endl;
    for (int i = 0; i < E; ++i)
    {
        int u, v, weight;
        cin >> u >> v >> weight;
        addEdge(graph, u, v, weight);
    }

    int startVertex;
    cout << "Enter the starting vertex: ";
    cin >> startVertex;

    vector<pii> mst = primMST(graph, startVertex);

    printMST(mst);

    return 0;
}
