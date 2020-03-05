#include<stdio.h>
using namespace std;

inline int min(int a, int b) { return a>b?b:a;}

int main() {
	
	int x, y, w, h;
	
	scanf("%d %d %d %d", &x, &y, &w, &h);
	printf("%d\n", min(x, min(y, min(w-x, h-y))));
}
