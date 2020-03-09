#include<stdio.h>
#include<cstring>
using namespace std;

int N,M;
int cache[90001];

inline int min(int a,int b) {return a>b?b:a;}

void getinfo() {
	scanf("%d %d", &N, &M);
	memset(cache, -1, sizeof(cache));
	return;
}

int divide(int n) {
	if(n == 1) return cache[1] = 0;

	int &ret = cache[n];
	if(ret != -1) return ret;

	ret = 1 + divide(n/2) + divide(n-(n/2));
	return ret;
}

int main() {
	getinfo();
	printf("%d\n", divide(N*M));
}
