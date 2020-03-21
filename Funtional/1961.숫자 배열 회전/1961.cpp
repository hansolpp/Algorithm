#include<cstdio>
#include<vector>
using namespace std;

int T;
int N;
int id;
vector<vector<int>> adj;
vector<vector<vector<int>>> ANSWERS;

void get_info() {
	scanf("%d", &N);
	adj = vector<vector<int>>(N, vector<int>(N,0));
	ANSWERS.clear();
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < N; j++) {
			scanf("%d", &adj[i][j]);
		}
	}
	return;
}

void print_all() {
	printf("#%d\n", ++id);
	for(int row = 0;  row < N; row++) {
		for(int shape = 2; shape >= 0; shape--) {
			for(int col = 0; col < N; col++) {
				printf("%d", ANSWERS[shape][row][col]);
			}
			printf(" ");
		}
		printf("\n");
	}
	return;
}

void solution() {
	int temp[7][7];
	for(int i = 0; i < 3; i++) {
		for(int i = 0; i < N; i++) {
			for(int j = 0; j < N; j++) {
				temp[i][j] = adj[i][j];
			}
		}
		for(int i = 0; i < N; i++) {
			for(int j = 0; j < N; j++) {
				adj[N-j-1][i] = temp[i][j];
			}
		}
		ANSWERS.push_back(adj);
	}
	print_all();
	return;
}

int main() {
	freopen("input.txt", "r", stdin);
	scanf("%d", &T);
	while(T--) {
		get_info();
		solution();
	}
}
