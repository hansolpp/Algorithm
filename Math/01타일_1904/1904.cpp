#include<cstdio>
using namespace std;

int N;

void get_info() {
	scanf("%d", &N);
	return;
}

int solution() {
	int two, one, zero, id;
	id = 2;
	one = 2;
	zero = 1;

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
