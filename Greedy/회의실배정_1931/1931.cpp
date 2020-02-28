#include<stdio.h>
#include<vector>
#include<algorithm>
#include<fstream>
using namespace std;

int N;
vector<pair<int,int>> table;

void getinfo() {

	int start, end;

	scanf("%d", &N);
	for(int i = 0; i < N; i++) {
		scanf("%d %d", &start, &end);
		table.push_back({end,start});
	}
}

int solution() {

	int count = 0;
	int endpoint = 0;
	sort(table.begin(), table.end());
	for(int i = 0; i < table.size(); i++) {

		if(endpoint <= table[i].second) {
			endpoint = table[i].first;
			count++;
		}
	}
	return count;
}

int main() {
	freopen("input.txt", "r", stdin);
	getinfo();
	printf("%d\n",solution());
}
