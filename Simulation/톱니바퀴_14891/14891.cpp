#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<vector>
using namespace std;

int gear_polar[5][8];
int spin_count;
int spin_queue[100][2];
vector<pair<int, int>> command;

void get_info() {
	
	// gear���� �� ����
	for (int i = 1; i < 5; i++) {
		int temp;
		scanf("%d", &temp);
		for (int j = 7; j >= 0; j--) {
			gear_polar[i][j] = temp % 10;
			temp /= 10;
			//printf("%d", gear_polar[i][j]);
		}
		//printf("\n");
	}

	scanf("%d", &spin_count);
	//printf("%d", spin_count);

	for (int i = 0; i < spin_count; i++) {
		scanf("%d %d", &spin_queue[i][0], &spin_queue[i][1]);
		//printf("%d %d", spin_queue[i][0], spin_queue[i][1]);
	}

	return;
}

void spin_one_gear(int gear_num, int spin_dir) {
	// �ð� �������� ȸ���Ҷ� (1)
	if (spin_dir == 1) {
		// 7�� idx ����
		int temp = gear_polar[gear_num][7];
		for (int i = 6; i >= 0; i--) {
			gear_polar[gear_num][i + 1] = gear_polar[gear_num][i];
		}
		gear_polar[gear_num][0] = temp;
	}


	// �ݽð� �������� (-1)
	else {
		// 0�� idx ����
		int temp = gear_polar[gear_num][0];
		for (int i = 1; i < 8; i++) {
			gear_polar[gear_num][i - 1] = gear_polar[gear_num][i];
		}
		gear_polar[gear_num][7] = temp;
	}

	return;
}

void spin_all_gear() {
	for (int i = 0; i < command.size(); i++) {
		spin_one_gear(command[i].first, command[i].second);
	}
	return;
}

void push_spin_all_gear(int start_gear_num, int start_gear_num_dir) {
	
	int left_remain_gear = start_gear_num;
	int right_remain_gear = 3 - start_gear_num;
	int spin_dir = start_gear_num_dir;

	// ó���� ������ ��� �ֱ�
	command.push_back({ start_gear_num, start_gear_num_dir });
	
	// ����
	for (int i = start_gear_num - 1; i >= 0; i--) {
		// ���� ���϶� (�̵����� ����)
		if (gear_polar[i + 1][6] == gear_polar[i][2]) break;
		// �ٸ� ���϶� (�̵���)
		if (gear_polar[i + 1][6] != gear_polar[i][2]) {
			spin_dir *= -1;
			// ȸ����
			command.push_back({i, spin_dir});
			//spin_one_gear(i, spin_dir);
		}
	}

	spin_dir = start_gear_num_dir;

	// ������
	for (int i = start_gear_num + 1; i < 5; i++) {
		// ���� ���϶� (�̵����� ����)
		if (gear_polar[i - 1][2] == gear_polar[i][6]) break;
		// �ٸ� ���϶� (�̵���)
		if (gear_polar[i - 1][2] != gear_polar[i][6]) {
			spin_dir *= -1;
			// ȸ����
			command.push_back({ i, spin_dir });
			//spin_one_gear(i, spin_dir);
		}
	}

	return;
}

int solution() {

	// ���� ȸ��
	for (int i = 0; i < spin_count; i++) {
		push_spin_all_gear(spin_queue[i][0], spin_queue[i][1]);
		spin_all_gear();
		command.clear();
	}

	// ���� ����
	int answer = 0;
	int temp = 1;
	for (int i = 1; i <= 4; i++) {
		if (gear_polar[i][0] == 1) {
			answer += temp;
		}
		temp *= 2;
	}

	return answer;
}

int main() {
	freopen("input.txt", "r", stdin);
	get_info();
	printf("%d", solution());
}