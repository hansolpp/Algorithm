#include <cstdio>
#include <cmath>
using namespace std;

double my_function(double w, double h, double x) {
    return h * x / w;
}

long long count_box(int w, int h) {

    long long useful_box = 0;

    for (int i = 0; i < w; i++) {
        long long unused_box = 0;

        // 아래꺼 정수
        if (my_function(w, h, i) - floor(my_function(w, h, i)) == 0 && my_function(w, h, i + 1) - floor(my_function(w, h, i + 1)) != 0) {
            unused_box = floor(my_function(w, h, i + 1)) - floor(my_function(w, h, i)) + 1;
        }
        // 위에꺼 정수
        else if (my_function(w, h, i + 1) - floor(my_function(w, h, i + 1)) == 0 && my_function(w, h, i) - floor(my_function(w, h, i)) != 0)
            unused_box = floor(my_function(w, h, i + 1)) - floor(my_function(w, h, i));
        // 둘 다 정수
        else if (my_function(w, h, i + 1) - floor(my_function(w, h, i + 1)) == 0 && my_function(w, h, i) - floor(my_function(w, h, i)) == 0)
            unused_box = floor(my_function(w, h, i + 1)) - floor(my_function(w, h, i));
        // 둘 다 정수 아닌거
        else {
            unused_box = floor(my_function(w, h, i + 1)) - floor(my_function(w, h, i)) + 1;
            if (floor(my_function(w, h, i + 1)) - floor(my_function(w, h, i)) == 0) unused_box = 1;
        }

        //printf("%d\n", unused_box);
        useful_box += h - unused_box;
    }
    return useful_box;
}

long long solution(int w, int h) {
    //가로가 w 세로가 h
    long long answer = count_box(w, h);
    return answer;
}