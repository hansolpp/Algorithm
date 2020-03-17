#include<stdio.h>
using namespace std;

int R,S;

void get_info() {
	scanf("%d %d", &R, &S);
	return;
}

int solution() {
	return 2*S-R;
}

int main() {
	get_info();
	printf("%d\n", solution());
}
