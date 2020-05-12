#include <string>
#include <vector>
#include <cmath>
using namespace std;

vector<int> make_vector(int n) {
    vector<int> origin_vector = { 0 };
    vector<int> result_vector = { 0 };
    for (int i = 2; i <= n; i++) {
        result_vector.push_back(0);
        for (int j = 1; j <= origin_vector.size(); j++) {
            result_vector.push_back(1 - origin_vector[origin_vector.size() - j]);
        }
        origin_vector = result_vector;
    }

    return result_vector;
}
vector<int> solution(int n) {
    vector<int> answer = make_vector(n);
    return answer;
}