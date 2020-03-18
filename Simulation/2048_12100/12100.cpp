#include<stdio.h>
#include<queue>
using namespace std;

int N;
int max_value;
int adj[20][20];

void get_info() {
	scanf("%d", &N);
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < N; j++) {
			scanf("%d", &adj[i][j]);
		}
	}
	return;
}

int move(int dir) {

	deque<int> dq;
	queue<int> result;

	switch(dir) {

	case 0:
		for(int i = 0; i < N; i++) {
			for(int j = 0; j < N; j++) {
				if(adj[j][i]) {
					dq.push_back(adj[j][i]);
					adj[j][i] = 0;
				}
			}

			int idx = 0;

			while(!dq.empty()) {
		
				int input_one = dq.front();
				dq.pop_front();
				if(dq.empty()) {
					result.push(input_one);
					break;
				}
				int input_two = dq.front();
				dq.pop_front();

				if(input_one == input_two) {
					input_one += input_one;
					result.push(input_one);
				}
				else{
					result.push(input_one);
					dq.push_front(input_two);
				}
			}
			while(!result.empty()) {
				int input = result.front();
				result.pop();

				max_value = max(max_value, input);

				adj[idx][i] = input;
				idx++;
			}
		}
		return max_value;


	case 1:
		for(int i = 0; i < N; i++) {
	        for(int j = N-1; j >= 0; j--) {
		        if(adj[i][j]) {
			        dq.push_back(adj[i][j]);
				    adj[i][j] = 0;
				}
			}   
			int idx = 0;
			while(!dq.empty()) {
           
				int input_one = dq.front();
				dq.pop_front();
				if(dq.empty()) {
					result.push(input_one);
					break;
				}
				int input_two = dq.front();
				dq.pop_front();

				if(input_one == input_two) {
					input_one += input_one;
					result.push(input_one);
				}
				else{
					result.push(input_one);
					dq.push_front(input_two);
				}
			}
			while(!result.empty()) {
				int input = result.front();
				result.pop();

				max_value = max(max_value, input);

				adj[i][N-1-idx] = input;
				idx++;
			}
		}
		return max_value;
	

	case 2:
		for(int i = N-1; i >= 0; i--) {
	        for(int j = N-1; j >= 0; j--) {
		        if(adj[j][i]) {
			        dq.push_back(adj[j][i]);
				    adj[j][i] = 0;
				}
			}   

			int idx = 0;

			while(!dq.empty()) {
            
				int input_one = dq.front();
				dq.pop_front();
				if(dq.empty()) {
					result.push(input_one);
					break;
				}
				int input_two = dq.front();
				dq.pop_front();

				if(input_one == input_two) {
					input_one += input_one;
					result.push(input_one);
				}
				else{
					result.push(input_one);
					dq.push_front(input_two);
				}
			}
			while(!result.empty()) {
				int input = result.front();
				result.pop();

				max_value = max(max_value, input);

				adj[N-1-idx][i] = input;
				idx++;
			}
		}
		return max_value;
	

	case 3:
		for(int i = 0; i < N; i++) {
	        for(int j = 0; j < N; j++) {
		        if(adj[i][j]) {
			        dq.push_back(adj[i][j]);
				    adj[i][j] = 0;
				}
			}   
			
			int idx = 0;

			while(!dq.empty()) {
            
				int input_one = dq.front();
				dq.pop_front();
				if(dq.empty()) {
					result.push(input_one);
					break;
				}
				int input_two = dq.front();
				dq.pop_front();

				if(input_one == input_two) {
					input_one += input_one;
					result.push(input_one);
				}
				else{
					result.push(input_one);
					dq.push_front(input_two);
				}
			}
			while(!result.empty()) {
				int input = result.front();
				result.pop();
	
				max_value = max(max_value, input);

				adj[i][idx] = input;
				idx++;
			}
		}
		return max_value;
	}
}

void DFS(int count) {
	if(count == 5) return;
	
	int copyBoard[20][20];
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < N; j++) {
			copyBoard[i][j] = adj[i][j];
		}
	}

	for(int i = 0; i < 4; i ++) {
		move(i);
		DFS(count+1);
		for(int i = 0; i < N; i++) {
			for(int j = 0; j < N; j++) {
				adj[i][j] = copyBoard[i][j];
			}
		}
	}
}

int main() {
	freopen("input.txt", "r", stdin);
	get_info();
	DFS(0);
	printf("%d\n", max_value);
}
