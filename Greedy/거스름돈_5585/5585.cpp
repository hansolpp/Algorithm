#include<cstdio>
#include<queue>
using namespace std;

int N;

void get_info() {
	scanf("%d", &N);
	return;
}

int solution() {
	N = 1000-N;
	int count = 0;
	queue<int> q;
	q.push(500);q.push(100);q.push(50);q.push(10);q.push(5);q.push(1);
	while(!q.empty()) {
		int divider = q.front();
		q.pop();

		count += N/divider;
		N = N%divider;
	}
	return count;
}

int main() {
	get_info();
	printf("%d\n", solution());
}
