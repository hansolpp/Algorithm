#include<stdio.h>
#include<vector>
using namespace std;

int N,B,C;
vector<int> place;

void get_info() {

	int temp;

	scanf("%d", &N);
	for(int i = 0; i < N; i++) {
		scanf("%d", &temp);
		place.push_back(temp);
	}
	scanf("%d %d", &B, &C);
	return;
}

long long solution() {
	long long person = 0;
	for(int i = 0; i < N; i++) {
		person++;
		place[i] -= B;
		if(place[i] > 0) {
			if(place[i]%C) person++;
			person+=place[i]/C;
		}
	}
	return person;
}

int main() {
	get_info();
	printf("%lld\n", solution());
}
