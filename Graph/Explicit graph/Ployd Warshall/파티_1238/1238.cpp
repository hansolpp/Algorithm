#include<stdio.h>
#include<vector>
#include<iostream>
//#include<fstream>
#define INF 10000000
using namespace std;

int N, M, X;
vector<vector<int>> adj;

void getinfo() {

	int s, d, r;

	scanf("%d %d %d", &N, &M, &X);
	adj = vector<vector<int>>(N+1, vector<int>(N+1, INF));

	for(int i = 0; i < M; i++) {
		scanf("%d %d %d", &s, &d, &r);
		adj[s][d] = r;
	}
	
	for(int j = 1; j <= N; j++) {
		adj[j][j] = 0;
	}
}

void floyd() {
	for(int k = 1; k <= N; k++) {
		for(int i = 1; i <= N; i++) {
			for(int j = 1; j <= N; j++) {
				if(adj[i][k] + adj[k][j] < adj[i][j]) {
					adj[i][j] = adj[i][k] + adj[k][j];
				}
			}
		}
	}
}

int solution() {

	int max_value = 0;
	int temp_value;

	for(int i = 1; i <= N; i++) {
		temp_value = adj[i][X] + adj[X][i];
		max_value = max(max_value, temp_value);
	}
	return max_value;
}

void printall() {
	for(int i = 1 ; i <= N; i++) {
		for(int j = 1; j <= N; j++) {
			printf("%d ", adj[i][j]);
		}
		printf("\n");
	}
}

int main() {

	//freopen("input.txt", "r", stdin);
	getinfo();
	floyd();
	cout << solution() << endl;
	//printall();
}
