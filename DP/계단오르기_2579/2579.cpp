#include<stdio.h>
#include<cstring>
#include<vector>
#include<iostream>
#include<fstream>
#define NEG_INF -100000000
using namespace std;

int N;
vector<int> step_value;
int result[301][3];

void getinfo() {

	scanf("%d", &N);
	memset(result, -1, sizeof(result));
	step_value.push_back(0);

	for(int i = 0; i < N; i++) {
		int temp;
		scanf("%d", &temp);
		step_value.push_back(temp);
	}
	return;
}

int moving(int here, int serial) {

	if(serial == 2) return NEG_INF;
	if(here > N) return NEG_INF;
	if(here == N) return result[here][serial] = step_value[here];

	int &ret = result[here][serial];
	if(ret != -1) return ret;

	return ret = step_value[here] + max(moving(here+1, serial+1), moving(here+2, 0));
}

int solution() {
	int max_value = 0;
	max_value = max(moving(1, 0), moving(2, 0));
	return max_value;
}

int main() {

	freopen("input.txt", "r", stdin);
	getinfo();
	cout << solution() << endl;
}
