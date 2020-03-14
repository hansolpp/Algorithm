#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;

int T,N;
vector<int> prepare;
vector<pair<int,int>> eat;

void get_info() {

	int temp;

	scanf("%d", &N);
	prepare = vector<int>();
	eat = vector<pair<int,int>>();

	for(int i =0; i < N; i++) {
		scanf("%d", &temp);
		prepare.push_back(temp);
	}
	for(int i = 0; i < N; i++) {
		scanf("%d", &temp);
		eat.push_back({-temp, i});
	}
	return;
}

int solution() {

	int result = 0;
	int max_value = 0;

	sort(eat.begin(), eat.end());

	for(int i = 0; i < N; i++) {
		int et = -eat[i].first;
		int pt = prepare[eat[i].second];

		result += pt;
		if(max_value < result + et) max_value = result + et;
	}
	return max_value;
}

int main() {
	scanf("%d", &T);
	while(T--) {
		get_info();
		printf("%d\n", solution());
	}
}
