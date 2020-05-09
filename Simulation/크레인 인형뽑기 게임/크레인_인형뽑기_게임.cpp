#include <string>
#include <vector>
#include <stack>
using namespace std;

// 판의 최대 크기는 30 x 30
// 하지만 commands의 원소로 인해 31 x 31로 지정한다.
vector<stack<int>> BUCKETS;
stack<int> ANSWER;

void make_stack(vector<vector<int>>& board) {
    // 1번 벡터부터 시작하기에 쓰레기값을 0번 index에 넣어줌
    stack<int> temp;
    BUCKETS.push_back(temp);
    int my_board_size = board[0].size();
    for (int col = 0; col < my_board_size; col++) {
        stack<int> bucket;
        for (int row = my_board_size - 1; row >= 0; row--) {
            if (board[row][col] == 0) continue;
            bucket.push(board[row][col]);
        }
        BUCKETS.push_back(bucket);
    }

    return;
}

int push_answer(int thing) {
    // 답이 아예 비어있으면
    if (ANSWER.empty()) {
        ANSWER.push(thing);
        return 0;
    }
    // ANSWER 확인
    int prev_top_element = ANSWER.top();
    // 현재와 전것이 같으면 펑하고 점수 추가
    if (prev_top_element == thing) {
        // 터짐
        ANSWER.pop();
        return 2;
    }
    // 현재와 전것이 같지 않으면
    // 뽑은거 넣기
    else if (prev_top_element != thing) {
        ANSWER.push(thing);
        return 0;
    }
    return 0;
}

int pick(vector<int> moves) {

    int result = 0;

    // moves 안에 있는 모든 명령어들에 대해 반복함
    for (size_t i = 0; i < moves.size(); i++) {
        stack<int>& stack_pos = BUCKETS[moves[i]];
        // 해당 스택에 제일 위에 있는거
        if (stack_pos.empty()) continue;
        int picked = stack_pos.top();
        // 제거
        stack_pos.pop();

        // ANSWER
        result += push_answer(picked);
    }

    return result;
}


// 움직임의 최대는 1000번
// 들어있는 원소는 1 ~ 1000
int solution(vector<vector<int>> board, vector<int> moves) {
    make_stack(board);

    int answer = pick(moves);
    return answer;
}