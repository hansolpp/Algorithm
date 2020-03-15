#include<stdio.h>
#include<algorithm>
using namespace std;

int N;
int w_time[1000];

void get_info() {
	scanf("%d", &N);
	for(int i = 0; i < N; i++) {
		scanf("%d", &w_time[i]);
	}
	return;
}

int solution() {

	int result = 0;
	int wait_time = 0;

	sort(w_time, w_time+N);

	for(int i = 0; i < N; i++) {
		wait_time += w_time[i];
		result += wait_time;
	}
	return result;
}

int main() {
	get_info();
	printf("%d\n", solution());
}
