#include<iostream>
#include<vector>
using namespace std;

vector<int> answer;
int W, H;
int map[50][50];
int dy[8] = {1, 1, 0, -1, -1, -1, 0, 1};
int dx[8] = {0, 1, 1, 1, 0, -1, -1, -1};

void getinfo() {

	cin >> W >> H;
	if( W == H && W == 0) {
		for(int i = 0; i < answer.size(); i++) {
			cout << answer[i] << endl;
		}
	}
	for(int i = 0 ; i < H; i++) {
		for(int j = 0; j < W; j++) {
			cin >> map[i][j];
		}
	}
	return;
}

bool isinside(int y, int x) {
	if(0<= y && y < H && 0 <= x && x < W) return true;
	else return false;
}

void dfs(int y, int x) {
	
	int next_y;
	int next_x;
	
	map[y][x] = 0;

	for(int i = 0; i < 8; i++) {
		next_y = y + dy[i];
		next_x = x + dx[i];

		if(map[next_y][next_x] == 1 && isinside(next_y, next_x)) {
			dfs(next_y, next_x);
		}
	}
	return;
}

int count_island(int y, int x) {
	dfs(y, x);
	return 1;
}

void solution() {

	int count = 0;

	for(int i = 0; i < H; i++) {
		for(int j = 0; j < W; j++) {
			if(map[i][j] == 1) {
				count += count_island(i, j);
			}
		}
	}
	answer.push_back(count);
	return;
}

int main() {
	
	while(1) {
		getinfo();
		if(H == W && H == 0) break;
		solution();
	}
}
