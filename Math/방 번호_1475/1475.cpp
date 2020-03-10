#include<stdio.h>
#include<stdlib.h>
#include<string.h>
using namespace std;

int set[10];
char temp[7];
int N;

void getinfo1() {
	scanf("%s", temp);
	return;
}

void getinfo2() {
	scanf("%d", &N);
	return;
}

inline int max(int a,int b) {return a>b?a:b;}

int solution1() {

	int max_value = 0;
	for(int i = 0; i < strlen(temp); i++) {
		int number = temp[i]-'0';
		set[number] += 1;
		if((number == 6) || (number == 9)) continue;
		if(max_value < set[number]) max_value = set[number];
	}
	return max(max_value,(set[6]+set[9]+1)/2);
}

int solution2() {
	
	int max_value = 0;
	while(1) {
		set[N%10]++;
		if(N/10==0) break;
		N/=10;
	}
	for(int i = 0; i < 10; i++) {
		if(i==6||i==9)continue;
		if(max_value<set[i])max_value=set[i];
	}
	return max(max_value,(set[6]+set[9]+1)/2);
}

int main() {
	getinfo2();
	printf("%d\n", solution2());
}
