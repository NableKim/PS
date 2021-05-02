#include <string>
#include <vector>
#include <iostream>
#include <queue>
#include <cmath>
using namespace std;

queue<string> q_ori;

char op[3] = { '+', '-', '*' };

void swap(int a, int b) {
    char tmp = op[a];
    op[a] = op[b];
    op[b] = tmp;
}

long long calc(string l, string r, char c) {

    long long left = stoll(l);
    long long right = stoll(r);

    switch (c) {
    case '+':
        return left + right;
        break;
    case '-':
        return left - right;
        break;
    case '*':
        return left * right;
        break;
    }
}

// 연산자 우선 
void set_op_priority(int depth, long long &answer) {
    if (depth == 3) {
        // Step 3. 1~3 순위 연산자에 맞게 계산하기
        queue<string> q = q_ori;

        // 3가지 연산자에 대해 계산 수행
        for (int k = 0; k < 3; k++) {
            int qSize = q.size();
            string left = "";
            bool flag = false;
            for (int i = 0; i < qSize; i++) {
                string front = q.front(); q.pop();
                // 숫자 아니면 연산자이잖아

                // 그러면 여기서 우선 이전 값을 저장해두고 queue에 넣지는 말자

                // 현재 꺼낸게 찾는 연산자이면
                // flag를 활성 시키고
                // 다음에 나오는 값과 같이 연산을 시켜야함

                // 현재 꺼낸게 찾는 연산자가 아니면
                // 그냥 left값만 갱신시키고 스킵
                if (front[0] == op[k]) {
                    flag = true;
                }
                else {
                    // 직전에 꺼낸 연산자가 찾는 연산자였다면
                    if (flag) {
                        // 이번에 꺼낸 피연산자와 연산을 진행
                        long long cal = calc(left, front, op[k]);
                        left = to_string(cal);
                        flag = false;
                    }
                    else {
                        // 기존의 left를 queue에 다시 넣기
                        if (left != "")
                            q.push(left);
                        left = front;   // left값 갱신
                    }
                }
            }
            q.push(left);
        }
        
        long long result = stoll(q.front()); q.pop();
        answer = abs(result) > answer ? abs(result) : answer;

        return;
    }

    for (int i = depth; i < 3; i++) {
        swap(depth, i); // depth번째에 i번째 위치한 값을 저장
        set_op_priority(depth + 1, answer);
        swap(depth, i);
    }
}

void parsing(string s) {

    string str = "";
    for (char& c : s) {
        if (c >= '0' && c <= '9')
            str += c;
        else {
            q_ori.push(str);    // 지금까지 나온 숫자 저장
            str = "";       // 피연산자 초기화
            str += c;       // 연산자
            q_ori.push(str);    // 연산자 저장
            str = "";       // 피연산자 초기화
        }
    }
    q_ori.push(str);    // 마지막 피연산자까지 저장
}

long long solution(string expression) {
    long long answer = 0;

    // Step 1. 연산자와 피연산자 구분해놓기
    parsing(expression);

    // Step 2. 연산자의 우선순위 정하기
    set_op_priority(0, answer);

    return answer;
}

int main() {
    string ex = "50*6-3*2";
    cout << solution(ex);
}


// 연산자와 피연산자를 구분해놓고
// 우선순위를 정하자

// 1번째 우선순위 연산자에 대해 계산해놓고
// 2번째 우선순위 연산자에 대해 계산
// 3번째..

// 결과 얻어서 최고값이랑 비교