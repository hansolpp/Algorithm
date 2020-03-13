#include<stdio.h>
#include<set>
#include<vector>
#include<algorithm>
#include<fstream>
using namespace std;

int C, N;
vector<int> rus, kor;

void get_info() {

	int temp;

	scanf("%d",&N);
	rus = vector<int>();
	kor = vector<int>();

	for(int i = 0; i < N; i++) {
		scanf("%d", &temp);
		rus.push_back(temp);
	}
	for(int i = 0; i < N; i++) {
		scanf("%d", &temp);
		kor.push_back(temp);
	}
	return;
}

int solution() {

	int count = 0;
	
	multiset<int> ratings(kor.begin(), kor.end());

	for(int p = 0; p < N; ++p) {
		if(*ratings.rbegin() < rus[p]) ratings.erase(ratings.begin());
	
		else {
			ratings.erase(ratings.lower_bound(rus[p]));
			++count;
		}
	}
	return count;
}

int main() {

	freopen("input.txt", "r", stdin);
	scanf("%d", &C);

	while(C--) {
		get_info();
		printf("%d\n", solution());
	}
}
