#include<cstdio>
using namespace std;

int N;

void get_info() {
	scanf("%d", &N);
	return;
}

int solution() {
	if(N == 1) return 1;
	if(N == 2) return 2;
	int two, one, zero, id;
	id = 2;
	one = 2;
	zero = 1;
	two = one + zero;

	while(id != N) {
		two = (one + zero)%15746;
		zero = one;
		one = two;
		id++;
	}
	return two;
}

int main() {
	get_info();
	printf("%d\n", solution());
}
