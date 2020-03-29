#include<cstdio>
#include<queue>
#include<cstring>
using namespace std;

int N, L;
int adj[100][100];
vector<vector<int>> BUCKET;
int visited[100];

void get_info() {
	scanf("%d %d", &N, &L);
	for(int i = 0; i < N; i++) {
		vector<int> bucket;
		for(int j = 0; j < N; j++) {
			scanf("%d", &adj[i][j]);
			bucket.push_back(adj[i][j]);
		}
		BUCKET.push_back(bucket);
	}

	for(int i = 0; i < N; i++) {
		vector<int> bucket;
		for(int j = 0; j < N; j++) {
			bucket.push_back(adj[j][i]);
		}
		BUCKET.push_back(bucket);
	}
	return;
}

bool going_up(int path, int from) {
	vector<int> x = BUCKET[path];
	int standard = x[from];
	int possible = true;
	for(int i = 1; i <= L; i++) {
		int idx = from-i;
		if(idx>=0&&!visited[idx]) {
			if(x[idx]+1 == standard) {
				visited[idx] = 1;
			}
			else return false;
		}
		else return false;
	}
	return possible;
}

bool going_down(int path, int from) {
	vector<int> x = BUCKET[path];
	int standard = x[from];
	int possible = true;
	for(int i = 1; i <= L; i++) {
		int idx = from+i;
		if(idx<N&&!visited[idx]) {
			if(x[idx]+1 == standard) {
				visited[idx] = 1;
			}
			else return false;
		}
		else return false;
	}
	return possible;
}

bool is_road(int path) {
	vector<int> x = BUCKET[path];
	int temp;
	int temp_idx;
	int ticket = 0;
	bool answer = true;
	for(int i = 0; i < x.size(); i++) {
		if(!i) {
			temp = x[i];
			temp_idx = i;
			continue;
		}
		//if you are going down, use this
		if(ticket) {
			ticket--;
			temp = x[i];
			temp_idx = i;
			continue;
		}

		if(temp == x[i]) {
			temp_idx = i;
			continue;
		}
		//going down
		else if(temp > x[i]){
			if(going_down(path, temp_idx)) {
				ticket = L-1;
				temp = x[i];
				temp_idx = i;
			}
			else answer = false;
		}
		//going up
		else{
			if(going_up(path, i)) {
				temp = x[i];
				temp_idx = i;
			}
			else answer = false;
		}
	}
	memset(visited, 0, sizeof(visited));
	return answer;
}

int search() {
	int road = 0;
	for(int i = 0 ; i < BUCKET.size(); i++) {
		if(is_road(i)) {
			road++;	
		}
	}
	return road;
}

int main() {
	freopen("input.txt", "r", stdin);
	get_info();
	printf("%d\n", search());
}
