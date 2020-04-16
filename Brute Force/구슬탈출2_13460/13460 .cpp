#pragma warning (disable:4996)
#include<cstdio>
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int N, M;
int adj[10][10];
pair<int, int> RED, BLUE, HOLE;
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};

void get_info() {
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) {
		string temp;
		cin >> temp;
		for (int j = 0; j < M; j++) {
			// 빈칸일때는 0
			if (temp[j] == '.') adj[i][j] = 0;
			// 장애물일때는 1
			if (temp[j] == '#') adj[i][j] = 1;
			// 구멍 -1
			if (temp[j] == 'O') {
				adj[i][j] = -1;
				HOLE.first = i;
				HOLE.second = j;
			}
			// 빨강 0
			if (temp[j] == 'R') {
				adj[i][j] = 0;
				RED.first = i;
				RED.second = j;
			}
			// 파랑 0
			if (temp[j] == 'B') {
				adj[i][j] = 0;
				BLUE.first = i;
				BLUE.second = j;
			}
		}
	}
	return;
}

void move(int dir) {
	// 움직이기 전의 빨간공 좌표
	pair<int, int> origin_red;
	origin_red.first = RED.first;
	origin_red.second = RED.second;
	//printf("%d, %d", origin_red.first, origin_red.second);
	// 빨강 먼저
	while (1) {;
		// 먼저 갈 수 있는곳인지 알아보기
		int ny = RED.first + dy[dir];
		int nx = RED.second + dx[dir];
		// 갈 수 있으면
		if (adj[ny][nx] == 0) {
			RED.first = ny;
			RED.second = nx;
		}
		// 막혀있으면
		else if(adj[ny][nx] == 1) break;
		// 구멍이면
		else if (adj[ny][nx] == -1) {
			RED.first = ny;
			RED.second = nx;
			break;
		}
	}

	// 움직이기 전의 파란공 좌표
	pair<int, int> origin_blue;
	origin_blue.first = BLUE.first;
	origin_blue.second = BLUE.second;
	// 다음 파랑
	while (1) {
		// 먼저 갈 수 있는곳인지 알아보기
		int ny = BLUE.first + dy[dir];
		int nx = BLUE.second + dx[dir];
		// 갈 수 있으면
		if (adj[ny][nx] == 0) {
			BLUE.first = ny;
			BLUE.second = nx;
		}
		// 막혀있으면
		else if (adj[ny][nx] == 1) break;
		// 구멍이면
		else if (adj[ny][nx] == -1) {
			BLUE.first = ny;
			BLUE.second = nx;
			break;
		}
	}

	// 이동한 것들의 좌표가 같을경우
	if (RED.first == BLUE.first && RED.second == BLUE.second) {
		// 둘다 구멍에 들어갈 경우
		if (RED.first == HOLE.first && RED.second == HOLE.second);
		// 겹칠경우
		else if (dir == 0) origin_red.first > origin_blue.first ? RED.first += 1 : BLUE.first += 1;
		else if (dir == 1) origin_red.second < origin_blue.second ? RED.second -= 1 : BLUE.second -= 1;
		else if (dir == 2) origin_red.first < origin_blue.first ? RED.first -= 1 : BLUE.first -= 1;
		else if (dir == 3) origin_red.second > origin_blue.second ? RED.second += 1 : BLUE.second += 1;
	}
	return;
}

int step(int dir, int count) {
	
	// 움직임이 10번이 초과된 경우
	if (count > 10) return 11;
	// 빨간색만 구멍에 빠질경우
	else if (adj[RED.first][RED.second] == -1 && adj[BLUE.first][BLUE.second] != -1) return count;
	// 둘다 구멍에 빠질경우
	else if (adj[RED.first][RED.second] == -1 && adj[BLUE.first][BLUE.second] == -1) return 11;
	// 파란색만 구멍에 빠질경우
	else if (adj[RED.first][RED.second] != -1 && adj[BLUE.first][BLUE.second] == -1) return 11;

	pair<int, int> save_red;
	save_red.first = RED.first;
	save_red.second = RED.second;
	pair<int, int> save_blue;
	save_blue.first = BLUE.first;
	save_blue.second = BLUE.second;

	int ret = 11;

	for (int i = 0; i < 4; i++) {
		// 전과 같은 방향으로 이동하거나, 반대방향으로 이동할 경우 넘어감
		if (i == dir || (i + 2) % 4 == dir) {
			if(count != 1) continue;
		}
		//printf("%d %d : %d\n", RED.first, RED.second, count + 1);
		move(dir);
		ret = min(ret, step(i, count + 1));

		RED.first = save_red.first;
		RED.second = save_red.second;
		BLUE.first = save_blue.first;
		BLUE.second = save_blue.second;
	}
	return ret;
}

int solution() {
	int result = 11;

	pair<int, int> save_red;
	save_red.first = RED.first;
	save_red.second = RED.second;
	pair<int, int> save_blue;
	save_blue.first = BLUE.first;
	save_blue.second = BLUE.second;

	for (int i = 0; i < 4; i++) {
		//move(i);
		result = min(result, step(i, 0));

		RED.first = save_red.first;
		RED.second = save_red.second;
		BLUE.first = save_blue.first;
		BLUE.second = save_blue.second;
	}
	if (result > 10) return -1;
	else return result;
}

int main() {
	freopen("input.txt", "r", stdin);
	get_info();
	printf("%d", solution());
}