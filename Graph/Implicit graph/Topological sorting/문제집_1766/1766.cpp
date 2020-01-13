#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int N, M;
vector<vector<int>> map;
vector<int> inDegree;

void get_info() {

	int a, b;

	cin >> N >> M;
	map = vector<vector<int>>(N+1, vector<int>());
	inDegree = vector<int>(N+1, 0);

	for(int i = 0; i < M; i++) {
		cin >> a >> b;
		map[a].push_back(b);
		inDegree[b]++;
	}
}

void topol_sort() {

	int x, y;
	priority_queue<int, vector<int>, greater<int>> q;
	
	for(int i = 1; i <= N; i++) {
		if(inDegree[i] == 0) q.push(i);
	}

	while(!q.empty()) {
		x = q.top();
		q.pop();

		printf("%d ", x);

		for(int i = 0; i < map[x].size(); i++){
			y = map[x][i];
			if(--inDegree[y] == 0) q.push(y);
		}
	}

}

int main() {
	get_info();
	topol_sort();
}
