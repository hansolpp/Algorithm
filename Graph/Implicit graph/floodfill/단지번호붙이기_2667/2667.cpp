#include<iostream>
#include<vector>
#include<stdio.h>
#include<algorithm>
using namespace std;

int N;
int map[25][25];
int area;
int dy[] = {1, 0, -1, 0};
int dx[] = {0, 1, 0, -1};
vector<int> answer;

void getinfo() {

	cin >> N;

	for(int i = 0; i < N; i++) {
		for(int j = 0; j < N; j++) {
			scanf("%1d", &map[i][j]);
		}
	}
	return;
}

bool isinside(int y, int x) {
	if(0<=y && y<N && 0<=x && x<N) return true;
	else return false;
}

void dfs(int y, int x) {
	
	int next_y, next_x;
	
	area++;
	map[y][x] = 0;

	for(int i = 0; i < 4; i++) {
		next_y = y + dy[i];
		next_x = x + dx[i];

		if(isinside(next_y, next_x) && map[next_y][next_x] == 1) {
			dfs(next_y, next_x);
		}
	}
	return;
}

int count_section(int y, int x) {
	dfs(y, x);
	return 1;
}

int solution() {

	int count = 0;

	for(int i = 0; i < N; i++) {
		for(int j = 0; j < N; j++) {
			if(map[i][j] == 1) {
				count += count_section(i, j);
				answer.push_back(area);
				area = 0;
			}
		}
	}
	return count;
}

void printall() {
	sort(answer.begin(), answer.end());
	for(int i = 0; i < answer.size(); i++) {
		cout << answer[i] << endl;
	}
	return;
}

int main() {
	
	getinfo();
	cout << solution() << endl;
	printall();
}
