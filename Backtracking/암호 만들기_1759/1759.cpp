#include<cstdio>
#include<algorithm>
using namespace std;

int L, C;
int keys[15]; //알파벳이 숫자로 표시됨
int alphabet[26]; // 자음 모음을 표시 0, 1, 모음이 1
int result[26]; // 고른것들 저장

void get_info() {
	char temp;
	scanf("%d %d", &L, &C);
	for(int i = 0; i < C; i++) {
		//공백도 문자로 받아버린다..
		while(1) {
			scanf("%c", &temp);
			if('a' <= temp && temp <= 'z') {
				//printf("%d ", temp);
				keys[i] = temp - 'a';
				break;
			}
		}
	}
	sort(keys, keys+C);
	alphabet[0] = 1;
	alphabet[4] = 1;
	alphabet[8] = 1;
	alphabet[14] = 1;
	alphabet[20] = 1;
	return;
}

void password(int pos, int m, int z, int count) {
	
	if((count == L) && (m > 0) && (z > 1)) {
		for(int i = 0; i < 26; i++) {
			if(result[i] == 1) printf("%c", i + 'a');
		}
		printf("\n");
	}

	for(int i = pos +1; i < C; i++) {
		int alpha_num = keys[i];
		//우선 해당 글자가 자음인지 모음인자 판단
		//모음이면
		if(alphabet[alpha_num] == 1) {
			result[alpha_num] = 1;
			password(i, m+1, z, count+1);
			result[alpha_num] = 0;
		}
		//자음이면
		else {
			result[alpha_num] = 1;
			password(i, m, z+1, count+1);
			result[alpha_num] = 0;
		}
	}
	return;
}

void solution() {
	for(int i = 0; i < C; i++) {
		int alpha_num = keys[i];
		if(alphabet[alpha_num] == 1) {
			result[alpha_num] = 1;
			password(i, 1, 0, 1);
			result[alpha_num] = 0;
		}
		else {
			result[alpha_num] = 1;
			password(i, 0, 1, 1);
			result[alpha_num] = 0;
		}
	}
	return;
}

int main() {
	freopen("input.txt", "r", stdin);
	get_info();
	solution();
}
