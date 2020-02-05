#include<iostream>
#include<vector>
#include<stack>
using namespace std;

int N;
vector<vector<int>> map;
vector<int> degree;
stack<int> path;

void get_info() {
	
	int temp;

	cin >> N;
	map = vector<vector<int>>(N+1, vector<int>(N+1, 0));
	degree = vector<int>(N+1, 0);

	for(int i = 1; i <= N; i++) {
		for(int j = 1; j <= N; j++) {
			cin >> temp;
			map[i][j] = temp;
			degree[i] += temp;
		}
	}
	return;
}

bool isEulerian() {
	for(int i = 1; i <= N; i++) {
		if(degree[i] % 2 == 1) return false;
	}
	return true;
}

void dfs(int source) {

	for(int i = 1; i <= N; i++) {
		while(map[source][i]) {
			map[source][i]--;
			map[i][source]--;
			dfs(i);
		}
	}
	path.push(source);
	return;
}

bool findEulerian_circuit() {
	if(isEulerian() == false) return false;
	dfs(1);
	return true;
}

int main() {

	int stack_size;

	get_info();
	if(findEulerian_circuit() == true) {

		stack_size = path.size();

		for(int i = 0; i < stack_size; i++) {
			cout << path.top() << " ";
			path.pop();
		}
		cout << endl;
	}
	else printf("-1");
}
