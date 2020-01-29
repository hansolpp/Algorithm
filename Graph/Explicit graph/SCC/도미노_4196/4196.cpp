#include<stdio.h>
#include<vector>
#include<stack>
#include<algorithm>
#include<cstring>
#define MAX 100001
using namespace std;

int T;
int N, M;
int id;
vector<vector<int>> map;
int visited[MAX];
bool finished[MAX];
int group[MAX];
bool inDegree[MAX];
stack<int> mystack;
vector<vector<int>> SCC;

void initalize() {
	id = 0;
	memset(visited, 0, sizeof(visited));
	memset(finished, 0, sizeof(finished));
	memset(group, 0, sizeof(group));
	memset(inDegree, 0, sizeof(inDegree));
	//mystack = stack<int>();
	SCC.clear();
}

void getinfo() {

	int x,y;

	scanf("%d %d", &N, &M);
	map = vector<vector<int>>(N + 1, vector<int>());

	for(int i = 0; i < M; i++) {
		scanf("%d %d", &x, &y);
		map[x].push_back(y);
	}
	return;
}

int dfs(int vertex, int origin){
	
	int parent;

	visited[vertex] = ++id;
	mystack.push(vertex);
	parent = visited[vertex];

	for(int i = 0; i < map[vertex].size(); i++) {
		int next = map[vertex][i];
		if(visited[next] == 0) parent = min(parent, dfs(next, origin));
		else if(!finished[next]) parent = min(parent, visited[next]);
	}

	if(visited[vertex] == parent) {
		vector<int> scc;
		while(1) {
			int temp = mystack.top();
			mystack.pop();
			scc.push_back(temp);
			group[temp] = SCC.size() + 1;
			finished[temp] = true;
			if(temp == vertex) break;
		}
		SCC.push_back(scc);
	}
	return parent;
}

void solution() {
	for(int i = 1; i <= N; i++) {
		if(visited[i] == 0) dfs(i,i);
	}
	
	for(int i = 1; i <= N; i++) {
		for(int j = 0; j < map[i].size(); j++) {
			int y = map[i][j];
			//연결되어 있는데 group이 다르다..즉 갈 수 있다.
			if(group[i] != group[y]) inDegree[group[y]] = true;
		}
	}
	
	int result = 0;
	for(int i = 1; i <= SCC.size(); i++) {
		//inDegree가 0(false)인것만 담겠다.
		if(!inDegree[i]) result++;
	}
	printf("%d\n", result);

	return;
}

int main() {
	scanf("%d", &T);
	while(T--) {
		getinfo();
		solution();
		initalize();
	}
}
