#include<stdio.h>
#include<cstring>
#include<fstream>
#include<string>
#include<iostream>
using namespace std;

int H, W;

const int coverType[4][3][2] = {
	{{0,0},{1,0},{0,1}},
	{{0,0},{0,1},{1,1}},
	{{0,0},{1,0},{1,1}},
	{{0,0},{1,0},{1,-1}}
};

int board[20][20];

void getinfo() {

	string temp;

	memset(board, 0, sizeof(board));
	scanf("%d %d", &H, &W);

	for(int i = 0; i < H; i++)  {
		cin >> temp;
		for(int j = 0; j < W; j++) {
			if(temp[j] == '#') board[i][j] = 1;
		}
	}
	return;
}

bool set(int y, int x, int type, int delta) {
	bool ok = true;
	for(int i = 0; i < 3; i++) {
		const int ny = y + coverType[type][i][0];
		const int nx = x + coverType[type][i][1];
		if(ny < 0 || ny >= H || nx < 0 || nx >= W) ok = false;
		else if((board[ny][nx] += delta) > 1) ok = false;
	}
	return ok;
}

int cover() {
	int y = -1, x = -1;
	for(int i = 0; i < H; i++) {
		for(int j = 0; j< W; j++) {
			if(board[i][j] == 0) {
				y = i;
				x = j;
				break;
			}
		}
		if(y != -1) break;
	}

	if(y == -1) return 1;
	int ret = 0;
	for(int type = 0; type < 4; type++) {
		if(set(y, x, type, 1)) ret += cover();
		set(y, x, type, -1);
	}
	return ret;
}

int solution() {
	int count = 0;
	for(int i = 0; i < H; i++) {
		for(int j = 0; j < W; j++) {
			count += cover();
		}
	}
	return count;
}

int main() {

	int C;
	
	freopen("input.txt", "r", stdin);
	scanf("%d", &C);

	while(C--) {
		getinfo();
		printf("%d\n", cover());
	}
}
