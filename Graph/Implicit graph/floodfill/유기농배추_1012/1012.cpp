#include<iostream>
#include<cstring>
#include<vector>
using namespace std;

int T;
int M, N, K;
int dy[] = {1,0, -1, 0};
int dx[] = {0,1,0,-1};
int map[50][50];
vector<int> answer;

void get_info() {
	
	int a, b;

	memset(map, 0, sizeof(map));
	cin >> M >> N >> K;

	for(int i = 0; i < K; i++) {
		cin >> a >> b;
		map[b][a] = 1;
	}
	return;
}

bool isinside(int y, int x) {
	if(0<= y && y <N && 0<=x && x<M) return true;
	else return false;
}

void dfs(int y, int x) {
	
	int next_y, next_x;

	for(int i = 0; i < 4; i++) {
		
		next_y = y + dy[i];
		next_x = x + dx[i];

		if(isinside(next_y, next_x) && map[next_y][next_x] == 1) {
			map[next_y][next_x] = 0;
			dfs(next_y, next_x);
		}
	}
	return;
}

int count_section(int y, int x) {
	map[y][x] = 0;
	dfs(y, x);
	return 1;
}

void solution() {

	int count = 0;

	for(int i = 0; i< N; i++) {
		for(int j = 0; j < M; j++) {
			if(map[i][j] == 1) {
				count += count_section(i, j);
			}
		}
	}
	answer.push_back(count);
	return;
}

void printall() {
	for(int i = 0; i < answer.size(); i++) {
		cout << answer[i] << endl;
	}
}

int main() {
	cin >> T;
	while(T--) {
		get_info();
		solution();
	}
	printall();
}
