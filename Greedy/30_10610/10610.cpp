#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

string N;

void get_info() {
	cin >> N;
	return;
}

bool cmp(char a, char b) {return a>b?true:false;}

string solution() {

	int sum = 0;
	bool zero = false;

	for(int i = 0; i < N.size(); i++) {
		sum += (N[i]-'0');
		if(!(N[i]-'0')) zero = true;
	}

	if(sum%3||!zero) return "-1";
	else {
		sort(N.begin(), N.end(), cmp);
	}
	return N;
}

int main() {
	get_info();
	cout << solution() << endl;
}
