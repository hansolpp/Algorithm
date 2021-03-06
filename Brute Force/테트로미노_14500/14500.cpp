#include<stdio.h>
#include<vector>
#include<iostream>
#include<fstream>
using namespace std;

int N, M;
int adj[500][500];
vector<vector<pair<int,int>>> shapes;

void getinfo() {
	scanf("%d %d", &N, &M);
	
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < M; j++) {
			scanf("%d", &adj[i][j]);
		}
	}
}

void make_shapes() {
	vector<pair<int,int>> shape;
	//1자모형
	shape = {{0,0},{0,1},{0,2},{0,3}};
	shapes.push_back(shape);
	shape = {{0,0},{1,0},{2,0},{3,0}};
	shapes.push_back(shape);
	//정사각형
	shape = {{0,0},{1,0},{0,1},{1,1}};
	shapes.push_back(shape);
	//ㄱ자(정)
	shape = {{0,0},{1,0},{2,0},{2,1}};
	shapes.push_back(shape);
	shape = {{0,0},{1,0},{0,1},{0,2}};
	shapes.push_back(shape);
	shape = {{0,0},{0,1},{1,1},{2,1}};
	shapes.push_back(shape);
	shape = {{0,0},{0,1},{0,2},{-1,2}};
	shapes.push_back(shape);
	//ㄱ자(대칭)
	shape = {{0,0},{1,0},{2,0},{2,-1}};
	shapes.push_back(shape);
	shape = {{0,0},{1,0},{1,1},{1,2}};
	shapes.push_back(shape);
	shape = {{0,0},{0,1},{1,0},{2,0}};
	shapes.push_back(shape);
	shape = {{0,0},{0,1},{0,2},{1,2}};
	shapes.push_back(shape);
	//번개
	shape = {{0,0},{1,0},{1,1},{2,1}};
	shapes.push_back(shape);
	shape = {{0,0},{0,1},{-1,1},{-1,2}};
	shapes.push_back(shape);
	shape = {{0,0},{1,0},{1,-1},{2,-1}};
	shapes.push_back(shape);
	shape = {{0,0},{0,1},{1,1},{1,2}};
	shapes.push_back(shape);
	//ㅗ
	shape = {{0,0},{0,1},{0,2},{-1,1}};
	shapes.push_back(shape);
	shape = {{0,0},{1,0},{2,0},{1,1}};
	shapes.push_back(shape);
	shape = {{0,0},{0,1},{0,2},{1,1}};
	shapes.push_back(shape);
	shape = {{0,0},{1,0},{2,0},{1,-1}};
	shapes.push_back(shape);
}

bool isinside(int y, int x) {
	if(0 <= y && y < N && 0 <= x && x < M) return true;
	return false;
}

int calculation() {
	int max_value = 0;
	int temp = 0;
	for(int shape = 0; shape < shapes.size(); shape++) {
		for(int row = 0; row < N; row++) {
			for(int col = 0; col < M; col++) {
				for(int count = 0; count < 4; count++) {
					if(isinside(row + shapes[shape][count].first, col + shapes[shape][count].second)) {
						temp += adj[row + shapes[shape][count].first][col + shapes[shape][count].second];
						if(count == 3) {
							//printf("%d %d\n", shape, temp);
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
	make_shapes();
	getinfo();
	printf("%d\n", calculation());
}
