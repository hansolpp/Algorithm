#include<iostream>
#include<stdio.h>
#include<cstring>
#include<fstream>
#define NEG_INF -10000000
using namespace std;

int N;
int period[16], reward[16];
int cache[16];

void getinfo() {

	int t, p;

	scanf("%d", &N);
	memset(cache, -1, sizeof(cache));

	for(int i = 1; i <= N; i++) {
		scanf("%d %d", &t, &p);
		period[i] = t;
		reward[i] = p;
	}
}

int schedule(int n) {
	if(n == N+1) return 0;
	if(n > N+1) return NEG_INF;
	
	int &ret = cache[n];
	if(ret != -1) return ret;

	return ret = max(schedule(n+1), schedule(n + period[n]) + reward[n]);
}

int main() {

	freopen("input.txt", "r", stdin);
	
	int max_val = 0;

	getinfo();
	max_val = schedule(1);
	cout << max_val << endl;
}
