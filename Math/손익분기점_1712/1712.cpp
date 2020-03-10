#include<stdio.h>
using namespace std;

int A,B,C;

void get_info() {
	scanf("%d %d %d", &A, &B, &C);
	return;
}

int solution() {
	if(B==C||B>C) return -1;
	return (A/(C-B)+1);
}

int main() {
	get_info();
	printf("%d\n", solution());
}
