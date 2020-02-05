#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int T;
int N, K;
int W;
vector<int> mytime;
vector<vector<int>> map;
vector<int> inDegree;
vector<int> max_value;
vector<int> answer;

void getinfo() {

	int a,b;

	cin >> N >> K;

	mytime = vector<int>(N+1, 0);
	map = vector<vector<int>>(N+1, vector<int>());
	inDegree = vector<int>(N+1, 0);

	for(int i = 1; i <= N; i++) {
		cin >> mytime[i];
	}

	for(int i = 0; i < K; i++) {
		cin >> a >> b;
		map[a].push_back(b);
		inDegree[b]++;
	}

	cin >> W;
	return;
}

void topo_sort() {
	
	queue<int> q;
	int x, y;

	max_value = vector<int>(N+1, 0);

	for(int i = 1; i <= N; i++) {
		if(inDegree[i] == 0) q.push(i);
	}

	while(!q.front() == W) {
		x = q.front();
		q.pop();

		for(int i = 0; i < map[x].size(); i++) {
			y = map[x][i];

			max_value[y] = max(max_value[y], max_value[x]+ mytime[x]);

			if(--inDegree[y] == 0) q.push(i);
		}
	}
	answer.push_back(max_value[W]);
	return;
}

void printall() {
	for(int i = 0; i < answer.size(); i++) {
		cout << answer[i] << endl;
	}
	return;
}

int main() {
	cin >> T;
	while(T--) {
		getinfo();
		topo_sort();
	}
	printall();
}
