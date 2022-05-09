#include<bits/stdc++.h>
using namespace std;
class Graph
{
	public:
	map<int,bool> visited;
	map<int,list<int>> adj;
	void addEdge(int v,int w);
	void DFS(int v);
};

void Graph::addEdge(int v,int w)
{
	adj[v].push_back(w);
	adj[w].push_back(v);
}

void Graph::DFS(int v)
{
	visited[v]=true;
	cout<<v<<" ";
	list<int>::iterator i;
	for(i=adj[v].begin(); i!=adj[v].end(); ++i)
	if(!visited[*i])
	DFS(*i);
}

int main()
{
	Graph g;
	g.addEdge(2,0);
	g.addEdge(0,8);
	g.addEdge(8,1);
	g.addEdge(2,1);	
	g.addEdge(2,2);	

	cout<<"The DFS is :";
	g.DFS(2);	
}