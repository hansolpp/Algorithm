#include<stdio.h>
#include<fstream>
#include<queue>
using namespace std;

int N, M, R, C, D;
int adj[50][50];
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

void getinfo() {
	scanf("%d %d", &N, &M);
	scanf("%d %d %d", &R, &C, &D);
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < M; j++) {
			scanf("%d", &adj[i][j]);
		}
	}
	return;
}

inline bool isinside(int y, int x) {return 0<=y&&y<N&&0<=x&&x<M;}

int moving() {

	int count = 0;

	queue<pair<pair<int,int>,int>> q;
	q.push({{R,C},D});

	while(!q.empty()) {
		int y = q.front().first.first;
		int x = q.front().first.second;
		int dir = q.front().second;
		q.pop();
		if(adj[y][x] == 0) {
			adj[y][x] = 2;
			count++;
		}
		bool flag = false;
		for(int i = 0; i < 4; i++) {
			int next_dir = (dir+(3-i))%4;
			int next_y = y + dy[next_dir];
			int next_x = x + dx[next_dir];

			if(isinside(next_y, next_x)) {
				if(!adj[next_y][next_x]) {
					q.push({{next_y,next_x},next_dir});
					flag = true;
					break;
				}
			}
		}
		if(!flag) {
			int back_y = y - dy[dir];
			int back_x = x - dx[dir];
			if(isinside(back_y, back_x)&&adj[back_y][back_x] != 1) {
				q.push({{back_y, back_x}, dir});
			}
			else break;
		}
	}
	return count;
}

int main() {
	freopen("input.txt", "r", stdin);
	getinfo();
	printf("%d\n", moving());
}
