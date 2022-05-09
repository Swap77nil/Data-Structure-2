#include <bits/stdc++.h>
using namespace std;
class Graph
{
public:
map<int, bool> visited;
map<int, list<int>> adj;
void addEdge(int v, int w);
void DFS(int v);
};
void Graph::addEdge(int v, int w)
{
adj[v].push_back(w);
adj[w].push_back(v);
}
void Graph::DFS(int v)
{
visited[v] = true;
cout << v << " ";
list<int>::iterator i;
for (i = adj[v].begin(); i != adj[v].end(); ++i)
if (!visited[*i])
DFS(*i);
}
int main()
{
Graph g;
g.addEdge(7, 5);
g.addEdge(8, 5);
g.addEdge(8, 8);
g.addEdge(9, 8);
g.addEdge(9, 9);
g.addEdge(5, 7);
cout << "Following is Depth First Traversal"
" (starting from vertex 2) \n";
g.DFS(7);
return 0;
}