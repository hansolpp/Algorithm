#include<stdio.h>
using namespace std;

int main() {
	int E,S,M;
	int e=1,s=1,m=1;
	int count = 1;
	scanf("%d %d %d", &E, &S, &M);
	while(1) {
		if((M==m)&&(S==s)&&(E==e)) {
            printf("%d\n", count);
			break;
        }
		e = (1+e)%16!=0?(1+e)%16:1;
		s = (1+s)%29!=0?(1+s)%29:1;
		m = (1+m)%20!=0?(1+m)%29:1;
		count++;
	}
}
