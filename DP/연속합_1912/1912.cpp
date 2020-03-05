#include<stdio.h>
#include<vector>
#include<fstream>
#include<algorithm>
using namespace std;

int N;
vector<int> array;

void getinfo() {

	int temp;

	scanf("%d", &N);

	for(int i = 0; i < N; i++) {
		scanf("%d", &temp);
		array.push_back(temp);
	}
	return;
}

int solution() {

	for(int i = 1; i < N; i++) {
		array[i] = max(array[i-1] + array[i], array[i]);
	}
	sort(array.begin(), array.end());
	return array[N-1];
}

int main() {
	freopen("input.txt", "r", stdin);
	getinfo();
	printf("%d\n", solution());
}
