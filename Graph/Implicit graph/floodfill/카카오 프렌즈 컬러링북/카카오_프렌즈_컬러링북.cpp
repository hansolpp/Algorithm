#include <vector>
#include <queue>
#include <cstdio>
using namespace std;

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

int max(int a, int b) {return a>b?a:b;}

bool isinside(int y, int x, int M, int N) {return 0<=y&&y<M&&0<=x&&x<N;}

int BFS(int y, int x, int M, int N, vector<vector<int>>& adj) {
	queue<pair<int,int>> q;
	int count = 0;
    int color = adj[y][x];

	q.push({y,x});
	adj[y][x] = 0;

	while(!q.empty()) {
		pair<int,int> element = q.front();
		q.pop();
		count++;

		for(int i = 0; i < 4; i++) {
			int next_y = element.first + dy[i];
			int next_x = element.second + dx[i];

			if(isinside(next_y, next_x, M, N)) {
				if(adj[next_y][next_x] == color) {
                    q.push({next_y, next_x});
				    adj[next_y][next_x] = 0;
                }
			}
		}
	}
	return count;
}

pair<int,int> BFS_all(int M, int N, vector<vector<int>>& adj) {
	
	int max_value = 0;
    int count = 0;

	for(int i = 0; i < M; i++) {
		for(int j = 0; j < N; j++) {
			if(adj[i][j]) {
				count++;
				max_value = max(max_value, BFS(i,j,M, N, adj));
			}
		}
	}
	return {count, max_value};
}

vector<int> solution(int m, int n, vector<vector<int>> picture) {

    pair<int,int> my_solution = BFS_all(m, n, picture);
    
    int number_of_area = my_solution.first;
    int max_size_of_one_area = my_solution.second;
    
    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    return answer;
}
