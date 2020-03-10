#include<stdio.h>
using namespace std;

int A,B,V;

void get_info() {
	scanf("%d %d %d", &A, &B, &V);
	return;
}

int solution() {
	int x = (V-A)/(A-B);
	if((A-B)*x + A != V) return x+2;
	else return x+1;
}

int main() {
	get_info();
	printf("%d\n", solution());
}
