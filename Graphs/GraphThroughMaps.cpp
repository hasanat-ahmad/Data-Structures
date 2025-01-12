#include <iostream>
#include <unordered_map>
#include <list>
using namespace std;

class Graph
{
public:
    unordered_map<int, list<int>> adj;

    void addEdge(int u, int v, bool direction)
    {
        // u is sourse node
        // v is destination node
        // Directed graph -> 1
        // Undirected graph -> 0

        // Now creating an edge from u to v
        adj[u].push_back(v);
        // This means that v is added to the list of neighbors for node u.
        if (direction == 0)
        {
            adj[v].push_back(u);
        }
    }

    void printAdjList()
    {
        for (auto i : adj)
        {
            cout << i.first << "->";
            for (auto j : i.second)
            {
                cout << j << " ";
            }
            cout << endl;
        }
    }
};

int main()
{

    int edges;
    int nodes;

    cout << "Enter the number of node: ";
    cin >> nodes;

    cout << "Enter the number of edges: ";
    cin >> edges;

    Graph g;
    cout << "Enter source node and destination node (u v): " << endl;

    for (int i = 0; i < edges; i++)
    {

        int u, v;

        cin >> u >> v;
        // creating an undirected graph
        g.addEdge(u, v, 0);
    }

    g.printAdjList();

    return 0;
}