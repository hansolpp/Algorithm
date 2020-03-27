#include<cstdio>
using namespace std;

int N;
int numbers[12];
bool visited[12];

void get_info() {
	scanf("%d", &N);
	for(int i = 0; i < N; i++) {
		scanf("%d", &numbers[i]);
	}
	return;
}

void print_case() {
	int idx = 0;
	while(idx != N) {
		if(visited[idx]) printf("%d ", numbers[idx]);
		++idx;
	}
	printf("\n");
	return;
}

void dfs(int pos, int count) {
	if(count == 6) return print_case();
	if(6 - count > N - pos) return;


	for(int i = pos + 1; i < N; i++) {
		visited[i] = 1;
		dfs(i, count+1);
		visited[i] = 0;
	}
	return;
}

void solution() {
	for(int i = 0; i < N; i++) {
		if(!visited[i]) {
			visited[i] = 1;
			dfs(i, 1);
			visited[i] = 0;
		}
	}
	return;
}

int main() {
	
	freopen("input.txt", "r", stdin);
	
	while(1) {
		get_info();
		if(N == 0) break;
		solution();
		printf("\n");
	}
}
