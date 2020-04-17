#pragma warning (disable:4996)
#include<cstdio>
#include<algorithm>
using namespace std;

int N;
int subset[100];
int my_operator[4];
int max_value = -987654321;
int min_value = 987654321;

void get_info() {
	// 숫자 갯수 받기
	scanf("%d", &N);
	// 숫자들 받기
	for (int i = 0; i < N; i++) {
		scanf("%d", &subset[i]);
	}
	// 연산자들 받기
	for (int i = 0; i < 4; i++) {
		scanf("%d", &my_operator[i]);
	}
	return;
}

void solution(int pos, int result, int plus, int minus, int mul, int div) {
	if (pos == N) {
		max_value = max(max_value, result);
		min_value = min(min_value, result);
		return;
	}

	int x = result;
	int y = subset[pos];
	int z;

	if (plus != 0) {
		z = x + y;
		solution(pos + 1, z, plus - 1, minus, mul, div);
	}
	if (minus != 0) {
		z = x - y;
		solution(pos + 1, z, plus, minus - 1, mul, div);
	}
	if (mul != 0) {
		z = x * y;
		solution(pos + 1, z, plus, minus, mul - 1, div);
	}
	if (div != 0) {
		z = x / y;
		solution(pos + 1, z, plus, minus, mul, div - 1);
	}
	return;
}

int main() {
	freopen("input.txt", "r", stdin);
	get_info();
	solution(1, subset[0], my_operator[0], my_operator[1], my_operator[2], my_operator[3]);
	printf("%d\n", max_value);
	printf("%d\n", min_value);
}