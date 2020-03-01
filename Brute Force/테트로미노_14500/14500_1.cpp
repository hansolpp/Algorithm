#include<stdio.h>
#include<vector>
#include<iostream>
#include<fstream>
using namespace std;

int N, M;
int adj[500][500];

int shapes[19][4][2] {
	{{0,0},{0,1},{0,2},{0,3}},
	{{0,0},{1,0},{2,0},{3,0}},
	{{0,0},{1,0},{0,1},{1,1}},
	{{0,0},{1,0},{2,0},{2,1}},
	{{0,0},{1,0},{0,1},{0,2}},
	{{0,0},{0,1},{1,1},{2,1}},
	{{0,0},{0,1},{0,2},{-1,2}},
	{{0,0},{1,0},{2,0},{2,-1}},
	{{0,0},{1,0},{1,1},{1,2}},
	{{0,0},{0,1},{1,0},{2,0}},
	{{0,0},{0,1},{0,2},{1,2}},
	{{0,0},{1,0},{1,1},{2,1}},
	{{0,0},{0,1},{-1,1},{-1,2}},
	{{0,0},{1,0},{1,-1},{2,-1}},
	{{0,0},{0,1},{1,1},{1,2}},
	{{0,0},{0,1},{0,2},{-1,1}},
	{{0,0},{1,0},{2,0},{1,1}},
	{{0,0},{0,1},{0,2},{1,1}},
	{{0,0},{1,0},{2,0},{1,-1}}
};

void getinfo() {
	scanf("%d %d", &N, &M);
	
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < M; j++) {
			scanf("%d", &adj[i][j]);
		}
	}
}

bool isinside(int y, int x) {
	if(0 <= y && y < N && 0 <= x && x < M) return true;
	return false;
}

int calculation() {
	int max_value = 0;
	int temp = 0;
	for(int shape = 0; shape < 19; shape++) {
		for(int row = 0; row < N; row++) {
			for(int col = 0; col < M; col++) {
				for(int count = 0; count < 4; count++) {
					if(isinside(row + shapes[shape][count][0], col + shapes[shape][count][1])) {
						temp += adj[row + shapes[shape][count][0]][col + shapes[shape][count][1]];
						if(count == 3) {
							max_value = max(max_value, temp);
							temp = 0;
						}
					}
					else {
						temp = 0;
						break;
					}
				}
			}
		}
	}
	return max_value;
}

int main() {
	freopen("input.txt", "r", stdin);
	getinfo();
	printf("%d\n", calculation());
}
