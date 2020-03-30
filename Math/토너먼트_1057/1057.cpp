#include<cstdio>
#include<queue>
using namespace std;

int N, K, I;
queue<int> before, after;

void get_info() {
	scanf("%d %d %d", &N, &K, &I);
	if(K>I) {
		int temp = K;
		K = I;
		I = temp;
	}
	for(int i = 1; i <= N; i++) {
		before.push(i);
	}
	return;
}

int tournament() {
	int idx = 1;
	while(!before.empty()) {
		int left = before.front();
		before.pop();
		if(before.empty()) {
			after.push(idx);
			if(left == I) I = idx;
			break;
		}
		int right = before.front();
		before.pop();

		if(left == K && right == I) return 1;
		else if(left == K || right == K) K = idx;
		else if(left == I || right == I) I = idx;

		after.push(idx);
		idx++;
	}
	swap(after,before);
	return 0;
}

int solution() {
	int round = 1;
	while(before.size() != 1) {
		if(tournament()) return round;
		round++;
	}
	return -1;
}

int main() {
	get_info();
	printf("%d\n", solution());
}
