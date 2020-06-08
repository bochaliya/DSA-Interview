/*
Detect cycle in a connected directed graph
Use DFS method
time - O(V+E)

*/

#include<bits/stdc++.h>
using namespace std;

void addEdge(vector<int> adj[], int u, int v) {
	adj[u].push_back(v);
}

bool detectCycle(vector<int> adj[], int V) {
	int s = 0;
	bool *visited = new bool[V];
	bool *recStack = new bool[V];
	for(int i = 0; i<V; i++) {
		visited[i] = false;
		recStack[i] = false;
	}
	stack<int> st;
	st.push(s);
	while(!st.empty()) {
		s = st.top();
		st.pop();
		for(auto x: adj[s]) {
			if(!visited[x]) {
				visited[x] = true;
				st.push(x);
			}
			else {
				return true;
			}
		}
	}
	return false;
}

int main(){
	int V = 4;
	vector<int> adj[V];
	addEdge(adj, 0, 1);
	addEdge(adj, 0, 2);
	addEdge(adj, 1, 2);
	//addEdge(adj, 2, 0);
	addEdge(adj, 2, 3);
	//addEdge(adj, 3, 3);
	if(detectCycle(adj, V)) {
		cout<<"Graph contain cycle"<<endl;
	}
	else {
		cout<<"Graph have no cycle"<<endl;
	}
	return 0;
}