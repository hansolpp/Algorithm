#include<stdio.h>
#include<iostream>
#include<queue>
#include<vector>
#include<cstring>
#include<fstream>
using namespace std;

int N, M;
int wall;
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};
int adj[8][8];
vector<int> adj_one_dimension;
bool visited[8][8];
vector<pair<int,int>> virus;

void getinfo() {

	int count = 0;

	scanf("%d %d", &N, &M);

	for(int i = 0; i < N; i++) {
		for(int j = 0; j < M; j++) {
			scanf("%d", &adj[i][j]);
			adj_one_dimension.push_back(adj[i][j]);
			if(adj[i][j] == 2) virus.push_back({i,j});
			if(adj[i][j] == 1) wall++;
		}
	}
}

bool isinside(int y, int x) {
	if(0 <= y && y < N && 0 <= x && x < M) return true;
	return false;
}

int bfs(int y, int x) {
	
	int count = 1;
	queue<pair<int,int>> q;

	visited[y][x] = true;
	q.push({y,x});

	while(!q.empty()) {
		pair<int,int> temp = q.front();
		q.pop();
		
		for(int i = 0; i < 4; i++) {
			int nexty = temp.first + dy[i];
			int nextx = temp.second + dx[i];
			if(!visited[nexty][nextx] && adj[nexty][nextx] == 0 && isinside(nexty, nextx)) {
				q.push({nexty, nextx});
				visited[nexty][nextx] = true;
				count++;
			}
		}
	}
	return count;
}

int bfs_all() {

	int count = 0;

	for(int i = 0; i < virus.size(); i++) {
		count += bfs(virus[i].first, virus[i].second);
	}
	return count;
}

int solution() {
	int min_value = 100;

	for(int i = 0; i < adj_one_dimension.size(); i++) {
		for(int j = i+1; j < adj_one_dimension.size(); j++) {
			for(int k = j+1; k < adj_one_dimension.size(); k++) {
				if(adj_one_dimension[i] == 0 && adj_one_dimension[j] == 0 && adj_one_dimension[k] == 0) {
					adj[i/M][i%M] = 1;
					adj[j/M][j%M] = 1;
					adj[k/M][k%M] = 1;

					min_value = min(min_value, bfs_all());
					memset(visited, 0, sizeof(visited));

					adj[i/M][i%M] = 0;
					adj[j/M][j%M] = 0;
					adj[k/M][k%M] = 0;
				}
			}
		}
	}
	return adj_one_dimension.size() - min_value - (wall+3);
}

int main() {

	freopen("input.txt", "r", stdin);
	getinfo();
	printf("%d\n", solution());
}
