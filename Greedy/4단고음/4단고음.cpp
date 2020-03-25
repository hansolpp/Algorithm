#include<cmath>
using namespace std;

int solving(int num, int star, int plus) {
    if((num == 1)&&(2*star == plus)) return 1;
    if((num<1)||(2*star>plus)) return 0;
    if(log(num)/log(3) < (plus - 2*star)/2) return 0;
    
    if((num%3==0)&&(2*star<=plus)) return solving(num/3, star+1, plus) + solving(num-1, star, plus+1);
    else return solving(num-1,star,plus+1);
}

int solution(int n) {
    
    int answer = solving(n, 0, 0);
    return answer;
}
