#include<cstdio>
#include<cmath>
#include<vector>
#include<algorithm>
using namespace std;

int adj[101][101];
int dy[] = {0,-1,0,1};
int dx[] = {1,0,-1,0};
int N;
int X, Y, D, G;

void dragon() {
	int generation = 0;
	vector<pair<int,int>> little_dragon;
	little_dragon.push_back({Y, X});
	little_dragon.push_back({Y+dy[D], X+dx[D]});

	while(generation != G) {
		pair<int,int> standard = little_dragon.back();
		int dragon_size = little_dragon.size();
		for(int i = dragon_size-2; i >= 0; i--) {
			int n_y = little_dragon[i].first - standard.first;
			int n_x = little_dragon[i].second - standard.second;
			int temp = n_y;

			n_y = n_x + standard.first;
			n_x = -temp + standard.second;
			if(0<=n_y&&n_y<=100&&0<=n_x&&n_x<=100)little_dragon.push_back({n_y, n_x});
		}
		generation++;
	}

	for(int i = 0; i < little_dragon.size(); i++) {
		int y = little_dragon[i].first;
		int x = little_dragon[i].second;
		adj[y][x] = 1;
	}
	return;
}

int count_all() {
	int count = 0;
	for(int i = 0; i < 101-1; i++) {
		for(int j = 0; j < 101-1; j++) {
			if(adj[i][j]&&adj[i+1][j]&&adj[i][j+1]&&adj[i+1][j+1]) count++;
		}
	}
	return count;
}

int solution() {
	scanf("%d", &N);
	for(int i = 0; i < N; i++) {
		scanf("%d %d %d %d", &X, &Y, &D, &G);
		dragon();
	}
	return count_all();
}

int main() {
	freopen("input.txt", "r", stdin);
	printf("%d\n", solution());
}
