#include<stdio.h>
using namespace std;

int N;
int answer[1001];

void make_tile() {

	answer[1] = 1;
	answer[2] = 2;

	for(int i = 3; i < 1001; i++) {
		answer[i] = (answer[i-1] + answer[i-2])%10007;	
	}
	return;
}

int main() {
	scanf("%d", &N);
	make_tile();
	printf("%d\n", answer[N]);
}
