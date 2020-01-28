#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<cstring>
#include<algorithm>
#include<stdio.h>

using namespace std;

int N, M;
int SOURCE;
vector<int> map[1001];

void bfs() {
	int check[1001];
	memset(check, 0, sizeof(check));
	queue<int> myqueue;
	myqueue.push(SOURCE);

	int start = SOURCE;
	check[start] = 1;

	while(!myqueue.empty()) {
		start = myqueue.front();
		
		myqueue.pop();
		printf("%d ", start);
		for(int i = 0; i < map[start].size(); i++) {
			if(check[map[start][i]] == 0 ) {
				myqueue.push(map[start][i]);
				check[map[start][i]] = 1;
			}
		}
	}
}

void dfs() {
	int check[1001];
	memset(check, 0, sizeof(check));
	stack<int> mystack;
	mystack.push(SOURCE);

	int start = SOURCE;
	check[start] = 1;
	
	printf("%d ", start);
	while(!mystack.empty()) {
		start = mystack.top();

		mystack.pop();
		for(int i = 0; i < map[start].size(); i++) {
			if(check[map[start][i]] == 0) {
				printf("%d ", map[start][i]);
				mystack.push(start);
				mystack.push(map[start][i]);
				check[map[start][i]] = 1;
				break;
			}
		}
	}
}

bool desc(int a, int b) {
	return a > b;
}

int main() {
	int start, end;

	cin >> N >> M >> SOURCE;
	for(int i = 0; i < M; i++) {
		cin >> start >> end;
		map[start].push_back(end);
		map[end].push_back(start);
	}

	for(int i = 0; i < N; i++){
		if(!map[i].empty()) sort(map[i].begin(), map[i].end());
	}

	dfs();
	cout << endl;
	
	for(int i = 0; i < N; i++) {
		if(!map[i].empty()) sort(map[i].begin(), map[i].end());
	}

	bfs();

}
