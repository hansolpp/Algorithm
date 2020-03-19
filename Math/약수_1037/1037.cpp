#include<stdio.h>
#include<algorithm>
using namespace std;

int N;
int element[50];

void get_info() {
	scanf("%d", &N);
	for(int i = 0; i < N; i++) {
		scanf("%d", &element[i]);
	}
	return;
}

int solution() {
	sort(element, element+N);
	return element[0]*element[N-1];
}

int main() {
	get_info();
	printf("%d\n", solution());
}
