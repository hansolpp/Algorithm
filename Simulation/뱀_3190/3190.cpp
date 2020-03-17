#include<stdio.h>
#include<iostream>
#include<deque>
#include<queue>
#include<string>
#include<fstream>
using namespace std;

int N;
int Apples;
int adj[100][100];
int L;
int dy[] = {-1,0,1,0};
int dx[] = {0,1,0,-1};
queue<pair<int,int>> commands;
deque<pair<int,int>> snake;

void get_info() {
	int x,y;
	string c;
	scanf("%d %d", &N, &Apples);
	for(int i = 0; i < Apples; i++) {
		scanf("%d %d", &y, &x);
		adj[y][x] = 1;
	}
	scanf("%d", &L);
	for(int i = 0; i < L; i++) {
		scanf("%d", &x);
		cin >> c;
		if(c == "L") commands.push({x,-1});
		else commands.push({x,1});
	}
	return;
}

bool isinside(int y, int x){return 1<=y&&y<=N&&1<=x&&x<=N;}

bool iscross(int y, int x){
	for(int i = 1; i < snake.size(); i++) {
		if(y == snake[i].first && x == snake[i].second) return true;
	}
	return false;
}

void move(int y, int x, int apple) {
	if(apple == 1) {
		snake.push_front({y,x});
		adj[y][x] = 0;
		return;
	}
	else{
			snake.push_front({y,x});
			snake.pop_back();
		}
	return;
}

int solution() {
	
	int dir = 1;
	int time = 0;

	snake.push_back({1,1});

	while(1) {
		int next_y = snake[0].first + dy[dir];
		int next_x = snake[0].second + dx[dir];
		time++;
		if(!isinside(next_y,next_x)) return time;

		if(iscross(next_y,next_x)) return time;
		move(next_y,next_x,adj[next_y][next_x]);


        if(commands.front().first == time) {
	        dir = (dir+4+commands.front().second)%4;
		    commands.pop();
        }
	}
}

int main() {
	freopen("input.txt", "r", stdin);
	get_info();
	printf("%d\n", solution());
}
