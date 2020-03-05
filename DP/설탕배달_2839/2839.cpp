#include<stdio.h>
#include<cstring>
#define INF 10000000
using namespace std;

int N;
int cache[5001];

void getinfo() {
	scanf("%d", &N);
	memset(cache, -1, sizeof(cache));
}

inline int min(int a, int b) {return a>b?b:a;}

int packing(int w) {
	if(w < 0) return INF;
	if(w == 0) return 0;

	int &ret = cache[w];
	if(ret != -1) return ret;

	return ret = 1 + min(packing(w-5), packing(w-3));
}

int solution() {
	int temp = packing(N);
	if(temp >= INF) return -1;
	else return temp;
}

int main() {
	getinfo();
	printf("%d\n", solution());
}
