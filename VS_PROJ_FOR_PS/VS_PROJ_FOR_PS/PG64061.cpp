#include <string>
#include <vector>
#include <iostream>
#include <queue>
#include <stack>
using namespace std;

// 각 열마다 큐가 존재해야할 것 같고...
// moves를 순회하며
// 현재 위치에 해당하는 큐에 프론트값을 꺼내서

// 바구니 스택에 넣어야하는데
// 바구니 스택의 탑이 현재 넣으려는 값과 같다면 정답에 +2를 해주고 pop해주기
// 그게 아니면 스택에 푸시만 해주기

int solution(vector<vector<int>> board, vector<int> moves) {
	int answer = 0;

	queue<int> q[31];
	stack<int> s;
	for (int y = 0; y < board.size(); y++) {
		for (int x = 0; x < board.size(); x++) {
			if(board[y][x]!=0)
				q[x].push(board[y][x]);
		}
	}

	for (int &t : moves) {

		t -= 1;	// 0부터 인덱스 시작

		if (q[t].empty())
			continue;

		int front = q[t].front(); q[t].pop();
		
		if (!s.empty() && s.top() == front) {
			s.pop();
			answer += 2;
		}
		else
			s.push(front);
	}

	return answer;
}

int main() {

	vector<vector<int>> board = { 
		{0, 0, 0, 0, 0}, 
		{ 0,0,1,0,3 }, 
		{ 0,2,5,0,1 }, 
		{ 4,2,4,4,2 }, 
		{ 3,5,1,3,1 } 
	};

	vector<int> moves = { 1,5,3,5,1,2,1,4 };

	cout << solution(board, moves);


	return 0;
}