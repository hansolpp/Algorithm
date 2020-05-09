#include <string>
#include <vector>
#include <stack>
using namespace std;

// ���� �ִ� ũ��� 30 x 30
// ������ commands�� ���ҷ� ���� 31 x 31�� �����Ѵ�.
vector<stack<int>> BUCKETS;
stack<int> ANSWER;

void make_stack(vector<vector<int>>& board) {
    // 1�� ���ͺ��� �����ϱ⿡ �����Ⱚ�� 0�� index�� �־���
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
    // ���� �ƿ� ���������
    if (ANSWER.empty()) {
        ANSWER.push(thing);
        return 0;
    }
    // ANSWER Ȯ��
    int prev_top_element = ANSWER.top();
    // ����� ������ ������ ���ϰ� ���� �߰�
    if (prev_top_element == thing) {
        // ����
        ANSWER.pop();
        return 2;
    }
    // ����� ������ ���� ������
    // ������ �ֱ�
    else if (prev_top_element != thing) {
        ANSWER.push(thing);
        return 0;
    }
    return 0;
}

int pick(vector<int> moves) {

    int result = 0;

    // moves �ȿ� �ִ� ��� ��ɾ�鿡 ���� �ݺ���
    for (size_t i = 0; i < moves.size(); i++) {
        stack<int>& stack_pos = BUCKETS[moves[i]];
        // �ش� ���ÿ� ���� ���� �ִ°�
        if (stack_pos.empty()) continue;
        int picked = stack_pos.top();
        // ����
        stack_pos.pop();

        // ANSWER
        result += push_answer(picked);
    }

    return result;
}


// �������� �ִ�� 1000��
// ����ִ� ���Ҵ� 1 ~ 1000
int solution(vector<vector<int>> board, vector<int> moves) {
    make_stack(board);

    int answer = pick(moves);
    return answer;
}