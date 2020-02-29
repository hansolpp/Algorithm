#include<stdio.h>
#include<vector>
using namespace std;

int main() {

	int N;
	int temp;
	int count = 0;
	vector<int> check;
	vector<bool> table(1001, 1);
	table[1] = 0;

	for(int i = 2; i*i <= 1001; i++) {
		if(table[i]) {
			for(int j = i * i; j <= 1001; j+=i) {
				table[j] = false;
			}
		}
	}

	scanf("%d", &N);
	for(int i = 0; i < N; i++) {
		scanf("%d", &temp);
		check.push_back(temp);
	}

	for(int i = 0; i < check.size(); i++) {
		if(table[check[i]]) count++;
	}
	printf("%d\n", count);
}
