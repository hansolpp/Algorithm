#include<cstdio>
#include<set>
using namespace std;

int R, C;
int adj[20][20];
set<int> alphabet;
bool visited[26];
int dy[] = {-1,0,1,0};
int dx[] = {0,1,0,-1};

void get_info() {

	char temp[20];

	scanf("%d %d", &R, &C);
	for(int i = 0; i < R; i++) {
		scanf("%s", temp);
		for(int j = 0; j < C; j++) {
			adj[i][j] = temp[j] - 'A';
		}
	}
	return;
}

bool isinside(int y, int x) {return 0<=y&&y<R&&0<=x&&x<C;}

int DFS(int y, int x, int count) { 
	if(visited[adj[y][x]]) return count;
	int ret = 1;
	visited[adj[y][x]] = 1;

	for(int i = 0; i < 4; i++) {
		int n_y = y + dy[i];
		int n_x = x + dx[i];
		if(isinside(n_y,n_x)) {
			ret = max(ret, DFS(n_y, n_x, count+1));
		}
	}

	visited[adj[y][x]] = 0;
	return ret;
}

int solution() {
	return DFS(0,0,0);
}

int main() {
	freopen("input.txt", "r", stdin);
	get_info();
	printf("%d\n", solution());
}
