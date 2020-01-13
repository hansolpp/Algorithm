#include<iostream>
#include<queue>
#include<stdio.h>
using namespace std;

int N, M;
int map[100][100];
int visited[100][100];
int dy[4] = {1, 0, -1, 0};
int dx[4] = {0, 1, 0, -1};

void get_info() {

	cin >> N >> M;
	
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < M; j++) {
			scanf("%1d", &map[i][j]);
		}
	}
}

bool isinside(int y, int x) {
	if(0<=y && y<N && 0<=x && x<M) return true;
	else return false;
}

int bfs() {
	
	int next_y;
	int next_x;
	int present_y, present_x;

	queue<pair<int, int>> q;
	q.push({0, 0});

	map[0][0] = 1;
	
	while(!q.empty()) {
		
		present_y = q.front().first;
		present_x = q.front().second;
		q.pop();

		visited[present_y][present_x] = 1;

		for(int i = 0; i < 4; i++) {
			next_y = present_y + dy[i];
			next_x = present_x + dx[i];

			if(map[next_y][next_x] == 1 && isinside(next_y, next_x) && visited[next_y][next_x] == 0) {
				
				map[next_y][next_x] = map[present_y][present_x] + 1;
				q.push({next_y, next_x});
			}
		}
	}
	return map[N-1][M-1];
}

int main() {
	get_info();
	cout << bfs() << endl;
}
