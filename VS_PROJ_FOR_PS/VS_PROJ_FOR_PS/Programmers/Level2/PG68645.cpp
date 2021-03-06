#include <iostream>
#include <string>
#include <queue>
#include <stack>
using namespace std;

// 선분을 그리는 방향은 크게 3가지
enum DIR {
    DOWN,       // 위에서 왼쪽 아래로 그리는 경우
    HORIZON,    // 왼쪽에서 오른쪽으로 (수평으로) 그리는 경우
    UP          // 오른쪽 아래에서 위로 그리는 경우
};

vector<int> solution(int n) {
    vector<int> answer;

    queue<int> q[1001];
    stack<int> s[1001];

    int num = 1;
    int index = 0;
    int dir = DOWN;

    // 선분은 n번 그리면 끝(선분의 길이는 n, n-1, n-2, ... , 2, 1)
    for (int len = n; len > 0; len--) {
        for (int i = 0; i < len; i++) {
            if (dir == DOWN)
                q[++index].push(num++);
            else if (dir == HORIZON)
                q[index].push(num++);
            else
                s[--index].push(num++);
        }
        dir = (dir + 1) % 3;
    }

    // answer 배열로 정답 만들어주기
    for (int i = 1; i <= n; i++) {
        while (!q[i].empty()) {
            answer.push_back(q[i].front());
            q[i].pop();
        }

        while (!s[i].empty()) {
            answer.push_back(s[i].top());
            s[i].pop();
        }
    }

    return answer;
}

int main() {
    vector<int> v = solution(4);

    for (int& a : v)
        cout << a << " ";

	return 0;
}