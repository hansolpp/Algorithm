#include<stdio.h>
#include<vector>
#include<stack>
#include<cstring>
#include<iostream>
#define MAX 40
using namespace std;

int N, M;
int id;
int visited[MAX], group[MAX];
bool finished[MAX];
vector<vector<int>> adj, SCC;
stack<int> mystack;

int opposite(int n) {return n%2 ? n-1 : n+1;}

void getinfo() {

	int u, v;

	scanf("%d %d", &N, &M);
	adj = vector<vector<int>>(2*N+1, vector<int>());

	for(int i = 0; i < M; i++) {

		scanf("%d %d", &u, &v);
		u = (u<0 ? -(u+1)*2 : u*2-1);
		v = (v<0 ? -(v+1)*2 : v*2-1);

		adj[opposite(u)].push_back(v);
		adj[opposite(v)].push_back(u);
	}
	return;
}

int dfs(int vertex) {
	
	int parent;

	visited[vertex] = ++id;
	mystack.push(vertex);
	parent = visited[vertex];

	for(int i = 0; i < adj[vertex].size(); i++) {
		int y = adj[vertex][i];
		if(visited[y] == 0) parent = min(parent, dfs(y));
		else if(!finished[y]) parent = min(parent, visited[y]);
	}

	if(parent == visited[vertex]) {
		vector<int> scc;
		while(1) {
			int x = mystack.top();
			mystack.pop();
			group[x] = SCC.size() + 1;
			scc.push_back(x);
			finished[x] = true;
			if(x == vertex) break;
		}
		SCC.push_back(scc);
	}
	return parent;
}

bool solution() {
	for(int i = 1; i <= 2*N; i++) {
		if(visited[i] == 0) dfs(i);
	}
	
	for(int i = 0; i < 2*N; i+=2) {
		if(group[i] == group[i+1]) return false;
	}
	
	return true;
}

int main() {
	getinfo();
	if(solution() == true) cout << "1" << endl;
	else cout << "0" << endl;
}
