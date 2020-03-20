#include<stdio.h>
#include<vector>
#define MAX 999999999
using namespace std;

int N;
int adj[21][21];
int player[21];

void get_info() {
	scanf("%d", &N);
	for(int i = 1; i <= N; i++) {
		for(int j = 1; j <= N; j++) {
			scanf("%d", &adj[i][j]);
		}
	}
	for(int i = 1; i <= N; i++) {
		for(int j = i+1; j <= N; j++) {
			adj[i][j] += adj[j][i];
		}
	}
	return;
}

int min(int a, int b) {return a>b?b:a;}

int DFS(int curr_player, int count) {
	if(count == N/2) {	
		int result = 0;
		vector<int> team_one, team_two;

		for(int i = 1; i <= N; i++) {
			if(player[i]) team_one.push_back(i);
			else team_two.push_back(i);
		}
		for(int i = 0; i < N/2; i++) {
			for(int j = i+1; j < N/2; j++) {
				result += adj[team_one[i]][team_one[j]];
				result -= adj[team_two[i]][team_two[j]];
			}
		}
		if(result < 0) return result*(-1);
		else return result;
	}

	int ret = MAX;

	for(int i = curr_player + 1; i <= N; i++) {
		if(player[i]) continue;
		if((N/2 - count) > (N-i+1)) continue;
		player[i] = 1;
		ret = min(ret, DFS(i, count+1));
		player[i] = 0;
	}
	return ret;
}

int main() {
	freopen("input.txt", "r", stdin);
	get_info();
	printf("%d\n", DFS(0, 0)); 
}
