#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int N, M;
vector<int> inDegree;
vector<vector<int>> map;

void getinfo() {

	int a, b;

	cin >> N >> M;
	map = vector<vector<int>>(N+1, vector<int>()); 
	inDegree = vector<int>(N+1, 0);

	for(int i = 0; i < M; i++) {
		cin >> a >> b;
		map[a].push_back(b);
		inDegree[b]++;
	}
	return;
}

void topo_sort() {
	queue<int> q;
	int x;
	int y;

	for(int i = 1; i <= N; i++) {
		if(inDegree[i] == 0) q.push(i);
	}

	while(!q.empty()) {
		x = q.front();
		q.pop();

		
		printf("%d ", x);

		for(int i = 0; i < map[x].size(); i++) {
			y = map[x][i];
			if(--inDegree[y] == 0) q.push(y);
		}
	}
	cout << endl;
	return;
}

int main() {
	getinfo();
	topo_sort();
}
