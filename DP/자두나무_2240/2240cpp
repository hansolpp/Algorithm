#include<stdio.h>
#include<iostream>
#include<cstring>
#include<fstream>
#define NEG_INF -999999999
using namespace std;

int T, W;
int plum[1001];
int cache[1001][31][3];

void getinfo() {
	scanf("%d %d", &T, &W);
	memset(cache, -1, sizeof(cache));

	for(int i = 1; i <= T; i++) {
		scanf("%d", &plum[i]);
	}
	return;
}

int moving(int sec, int w, int pos) {
	if(w > W) return NEG_INF;
	if(sec == T) return plum[sec] == pos ? 1 : 0;
	
	int &ret = cache[sec][w][pos];
	if(ret != -1) return ret;

	int present = 0; 
	if(plum[sec] == pos) present = 1;

	return ret =  present + \
					max(moving(sec+1, w, pos), moving(sec+1, w+1, 3-pos));
}

int solution() {
	int answer = max(moving(1,0,1), moving(1,1,2));
	return answer;
}

int main() {
	freopen("input.txt", "r", stdin);
	getinfo();
	printf("%d\n", solution());
}
