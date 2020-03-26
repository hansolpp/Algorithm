#include <iostream>

using namespace std;

int N;
int col[15];

void get_info() {
	scanf("%d", &N);
	return;
}

bool ispossible(int i) {
    for(int j=0;j<i;j++)
    {
        if(col[j] == col[i] || abs(col[i]-col[j]) == (i-j))
            return false;
    }
    return true;
}
int deploy(int i) {
    if(i == N) return 1;
	int ret = 0;

    for(int j=0;j<N;j++)
    {
        col[i] = j;
		if(ispossible(i)) ret += deploy(i+1);
    }
	return ret;
}

int main()
{
	get_info();
	printf("%d\n", deploy(0));
    return 0;
}
