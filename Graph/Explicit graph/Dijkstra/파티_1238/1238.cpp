#include<stdio.h>
#include<vector>
#include<iostream>
#include<queue>
#include<fstream>
#define INF 10000000
using namespace std;

int N , M , X;
vector<vector<pair<int,int>>> adj;
vector<vector<pair<int,int>>> rev_adj;

void getinfo() {
	
	int s, d, v;

	scanf("%d %d %d", &N, &M, &X);
	adj = vector<vector<pair<int, int>>>(N+1, vector<pair<int,int>>());
	rev_adj = vector<vector<pair<int,int>>>(N+1, vector<pair<int,int>>());

	for(int i = 0; i < M; i++) {
		scanf("%d %d %d", &s, &d, &v);
		adj[s].push_back({v, d});
		rev_adj[d].push_back({v, s});
	}
}

vector<int> dijkstra(int source) {

	vector<int> dist(N+1, INF);
	dist[source] = 0;
	priority_queue<pair<int,int>> pq;
	pq.push({0, source});

	while(!pq.empty()) {
		int cost = -pq.top().first;
		int here = pq.top().second;
		pq.pop();

		if(dist[here] < cost) continue;

		for(int i = 0; i < adj[here].size(); i++) {
			int there = adj[here][i].second;
			int nextDist = cost + adj[here][i].first;
			if(nextDist < dist[there]) {
				dist[there] = nextDist;
				pq.push({-nextDist, there});
			}
		}
	}
	return dist;
}

vector<int> rev_dijkstra(int source) {

	vector<int> dist(N+1, INF);
	dist[source] = 0;
	priority_queue<pair<int,int>> pq;
	pq.push({0, source});

	while(!pq.empty()) {
		int cost = -pq.top().first;
		int here = pq.top().second;
		pq.pop();

		if(dist[here] < cost) continue;

		for(int i = 0; i < rev_adj[here].size(); i++) {
			int there = rev_adj[here][i].second;
			int nextDist = cost + rev_adj[here][i].first;
			if(nextDist < dist[there]) {
				dist[there] = nextDist;
				pq.push({-nextDist, there});
			}
		}
	}
	return dist;
}

int solution() {

	int max_value = 0;
	vector<int> result(N+1, 0);
	vector<int> from = dijkstra(X);
	vector<int> to = rev_dijkstra(X);

	for(int i = 1; i <= N; i++) {
		result[i] = from[i] + to[i];
		max_value = max(max_value, result[i]);
	}
	/*
	for(int j = 0; j <= N; j++) {
		printf("%d ", result[j]);
	}
	*/
	return max_value;
}


int main() {

	freopen("input.txt", "r", stdin);
	getinfo();
	cout << solution() << endl;
}
