#include<stdio.h>
#include<queue>
#include<fstream>
using namespace std;

int N, M, X, Y, K;
int adj[20][20];
queue<int> commands;
int dy[] = {0,0,0,-1,1};
int dx[] = {0,1,-1,0,0};
int dice[7];

void getinfo() {

	int temp;

	scanf("%d %d %d %d %d", &N, &M, &X, &Y, &K);
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < M; j++) {
			scanf("%d", &adj[i][j]);	
		}
	}
	for(int i = 0; i < K; i++) {
		scanf("%d", &temp);
		commands.push(temp);
	}
	return;
}	

void move(int dir) {
	
	int temp1;
	int temp2;
	if(dir == 1) {
		temp1 = dice[1];
		temp2 = dice[3];
		dice[1] = dice[4];
		dice[3] = temp1;
		dice[4] = dice[6];
		dice[6] = temp2;
	}

	if(dir == 2) {
		temp1 = dice[1];
		temp2 = dice[4];
		dice[1] = dice[3];
		dice[3] = dice[6];
		dice[4] = temp1;
		dice[6] = temp2;
	}

	if(dir == 3) {
		temp1 = dice[1];
		temp2 = dice[2];
		dice[1] = dice[5];
		dice[2] = temp1;
		dice[5] = dice[6];
		dice[6] = temp2;
	}

	if(dir == 4) {
		temp1 = dice[1];
		temp2 = dice[5];
		dice[1] = dice[2];
		dice[2] = dice[6];
		dice[5] = temp1;
		dice[6] = temp2;
	}
	return;
}

bool isinside(int y, int x) {
	return 0 <= y && y < N && 0 <= x && x < M;
}

void solution() {

	int ny = X;
	int nx = Y;

	if(adj[ny][nx] != 0) {
		dice[6] = adj[ny][nx];
		adj[ny][nx] = 0;
	}

	while(!commands.empty()) {

		int next_dir = commands.front();
		commands.pop();
		ny += dy[next_dir];
		nx += dx[next_dir];

		if(isinside(ny, nx)) {
			move(next_dir);
			if(adj[ny][nx] == 0) adj[ny][nx] = dice[6];
			else {
				dice[6] = adj[ny][nx];
				adj[ny][nx] = 0;
			}
			printf("%d\n", dice[1]);
		}
		else {
			ny -= dy[next_dir];
			nx -= dx[next_dir];
		}
	}
	return;
}

int main() {
	freopen("input.txt", "r", stdin);
	getinfo();
	solution();
}
