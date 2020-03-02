#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<string>
using namespace std;

int sum(int N) {
	int newone = N/10 + N%10;
	return (N%10)*10 + newone%10;
}

int main() {
	int N;
	int count = 1;
	int temp;
	scanf("%d", &N);
	temp = sum(N);

	while(!(N == temp)) {
		temp = sum(temp);
		count++;
	}
	printf("%d\n", count);
}
