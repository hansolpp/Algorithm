#include<stdio.h>
#include<queue>
using namespace std;

int X;
priority_queue<int> bucket;

void get_info() {
	scanf("%d", &X);
	return;
}

int solution() {

	int my_length = 64;

	bucket.push(-64);

	while(1) {
		
		int small_stick = -bucket.top();
		bucket.pop();

		if(my_length == X) return bucket.size()+1;

		if(my_length > X) {
			if(my_length - small_stick/2 >= X) {
				my_length = my_length - small_stick/2;
				bucket.push(-small_stick/2);
			}
			else{
				bucket.push(-small_stick/2);
				bucket.push(-small_stick/2);
			}
		}
	}
}

int main() {
	get_info();
	printf("%d\n", solution());
}
