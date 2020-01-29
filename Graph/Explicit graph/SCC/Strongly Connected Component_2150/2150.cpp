#include<stdio.h>
#include<stack>
#include<vector>
#include<algorithm>
#define MAX 10001
using namespace std;

int V, E;
int id;
int visited[MAX];
bool finished[MAX];
vector<vector<int>> map;
vector<vector<int>> SCC;
stack<int> s;

void getinfo() {

	int in, out;

	scanf("%d %d", &V, &E);
	map = vector<vector<int>>(V+1, vector<int>());

	for(int i = 0; i < E; i++) {
		scanf("%d %d", &in, &out);
		map[in].push_back(out);
	}
	return;
}

int dfs(int vertex) {
	
	int parent;
	int y;
	
	visited[vertex] = ++id;
	s.push(vertex);
	parent = visited[vertex];

	for(int i = 0; i < map[vertex].size(); i++) {
		y = map[vertex][i];
		if(visited[y] == 0) parent = min(parent, dfs(y));
		else if(!finished[y]) parent = min(parent, visited[y]);
	}

	if(parent == visited[vertex]) {
		vector<int> scc;
		while(1) {
			int t = s.top();
			s.pop();
			scc.push_back(t);
			finished[t] = true;
			if(t == vertex) break;
		}
		sort(scc.begin(), scc.end());
		scc.push_back(-1);
		SCC.push_back(scc);
	}
	return parent;
}

void solution() {
	for(int i = 1; i <= V; i++) {
		if(visited[i] == 0) dfs(i);
	}
	return;
}

void print_answer() {
	printf("%d\n", SCC.size());
	sort(SCC.begin(), SCC.end());
	for(int i = 0; i < SCC.size(); i ++) {
		for(int j = 0; j < SCC[i].size(); j++) {
			printf("%d ", SCC[i][j]);
		}
		printf("\n");
	}
	return;
}

int main() {
	getinfo();
	solution();
	print_answer();
}
