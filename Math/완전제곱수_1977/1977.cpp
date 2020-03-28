#include<cstdio>
#include<cmath>
#include<vector>
using namespace std;

int M, N;

void get_info() {
	scanf("%d %d", &M, &N);
	return;
}

vector<int> solution() {
	vector<int> answer;
	int left = ceil(sqrt((float)M));
	int right = floor(sqrt((float)N));
	int sum_result = 0;
	int min_value = 987654321;

	if(right<left) {
		answer.push_back(-1);
		return answer;
	}

	for(int start = left; start <= right; start++) {
		sum_result += start*start;
		min_value = min(min_value, start*start);
	}
	answer.push_back(sum_result);
	answer.push_back(min_value);
	return answer;
}

int main() {
	get_info();
	vector<int> answer = solution();
	for(int i = 0 ; i < answer.size(); i++) {
		printf("%d\n", answer[i]);
	}
}
