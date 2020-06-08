/*
BFS for connected graph
Graph may contains cycles. To avoid processing a node more than once, we use a boolean visited array.
Time- O(V+E)

*/

#include<bits/stdc++.h>
using namespace std;

void addEdge(vector<int> adj[], int u, int v) {
	adj[u].push_back(v);
	adj[v].push_back(u);
}

void bfs(vector<int> adj[], int V, int s) {
	bool *visited = new bool[V];
	for(int i = 0; i < V; i++) {
		visited[i] = false;
	}

	queue<int> q;
	visited[s] = true;
	q.push(s);
	while(!q.empty()) {
		s = q.front();
		cout<<s<<" ";
		q.pop();

		for(auto x : adj[s]) {
			if(!visited[x]) {
				q.push(x);
				visited[x] = true;
			}
		}
	}
	cout<<endl;
}

int main(){
	int V = 4;
	vector<int> adj[V];
	addEdge(adj, 0, 1);
	addEdge(adj, 0, 2);
	addEdge(adj, 1, 2);
	addEdge(adj, 2, 0);
	addEdge(adj, 2, 3);
	addEdge(adj, 3, 3);
	cout<<"starting vertex 2"<<endl;
	bfs(adj, V, 2);
	return 0;
}