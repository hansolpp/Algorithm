#include<stdio.h>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;

int T;
int N, M;
int id;
vector<vector<int>> map, SCC;
vector<int> visited;
vector<bool> finished, mycheck;
stack<int> mystack;
vector<int> group;


void getinfo() {
	int a, b;

	scanf("%d %d", &N, &M);
	map = vector<vector<int>>(N, vector<int>());
	SCC = vector<vector<int>>();
	visited = vector<int>(N, 0);
	group = vector<int>(N, 0);
	finished = vector<bool>(N, false);
	mycheck = vector<bool>(N, false);
	id = 0;

	for(int i = 0; i < M; i++) {
		scanf("%d %d", &a, &b);
		map[a].push_back(b);
	}
}

int dfs(int source) {
	
	int parent;

	visited[source] = ++id;
	mystack.push(source);
	parent = visited[source];

	for(int i = 0; i < map[source].size(); i++) {
		int y = map[source][i];
		if(visited[y] == 0) parent = min(parent, dfs(y));
		else if(!finished[y]) parent = min(parent, visited[y]);
	}

	if(parent == visited[source]) {
		vector<int> scc;
		while(1) {
			int x = mystack.top();
			mystack.pop();
			scc.push_back(x);
			group[x] = SCC.size() + 1;
			finished[x] = true;
			if(x == source) break;
		}
		SCC.push_back(scc);
	}
	return parent;
}

void solution() {

	int count = 0;

	for(int i = 0; i < N; i++) {
		if(visited[i] == 0) dfs(i);
	}

	for(int i = 0; i < N; i++) {
		for(int j = 0; j < map[i].size(); j++) {
			int y = map[i][j];
			if(group[i] != group[y]) mycheck[group[y]] = true;
		}
	}

	for(int i = 1; i <= SCC.size(); i++) {
		if(!mycheck[i]) count++;
	}

	if(count == 1) {

		int SCC_index = SCC.size()-1;

		sort(SCC[SCC_index].begin(), SCC[SCC_index].end());

		for(int i = 0; i < SCC[SCC_index].size(); i++) {
			printf("%d\n", SCC[SCC_index][i]);
		}
	}
	else {
		printf("Confused\n");
	}
}

int main() {
	scanf("%d", &T);
	while(T--) {
		getinfo();
		solution();
		printf("\n");
	}
}
