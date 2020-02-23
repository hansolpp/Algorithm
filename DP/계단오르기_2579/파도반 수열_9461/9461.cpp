#include<stdio.h>
#include<cstring>
#include<iostream>
using namespace std;

int T;
int N;
long long cache[101];

void getinfo() {
	scanf("%d", &N);
	return;
}

void init_value() {
	memset(cache, -1, sizeof(cache));
	cache[1] = 1;
	cache[2] = 1;
	cache[3] = 1;
	cache[4] = 2;
	cache[5] = 2;

	for(int i = 6; i <= 100; i++) {
		cache[i] = cache[i-5] + cache[i-1];
	}

	return;
}

int main() {

	scanf("%d", &T);
	init_value();	

	while(T--) {
		getinfo();
		cout << cache[N] << endl;
	}
}
