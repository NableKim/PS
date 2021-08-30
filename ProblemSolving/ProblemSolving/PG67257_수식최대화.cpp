/*
* 연산자에 대한 우선 순위를 순열로 구한 후,
* 구한 우선순위에 따라 연산식을 계산해내는 문제
* 시간복잡도 : O(N^2), N은 주어진 입력 문자열의 길이 (<=100)
* 제일 최악의 경우는 입력 문자열이 "1+2*3*5..." 과 같이 피연산자, 연산자가 문자열 길이 1개씩 차지하는 경우임
*/

#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <cmath>
using namespace std;

char arr[3] = { '+', '-', '*' };    // 연산자 우선순위 배열
string inStr;                       // 입력으로 주어진 문자열
deque<string> dq;                   // 주어진 연산에 따라 계산결과를 저장할  dq
long long answer = 0;               // 정답

// 주어진 입력 문자열을 갖고 dq에 계산결과 초기 세팅하는 함수
void initDq(string expression) {

    // dq 초기화
    dq.clear();

    // 연산자 우선순위 정하기
    string tmp = "";
    for (int i = 0; i < expression.size(); i++) {
        if (expression[i] >= '0' && expression[i] <= '9')
            tmp += expression[i];
        else {
            dq.push_back(tmp);
            tmp = "";
            tmp += expression[i];
            dq.push_back(tmp);
            tmp = "";
        }
    }
    dq.push_back(tmp); // ex) "100" "-" "200" "*" "300" ... 이런 식으로 저장
}

void swap(int index1, int index2) {
    int tmp = arr[index1];
    arr[index1] = arr[index2];
    arr[index2] = tmp;
}

// 연산자에 따른 계산 함수
long long operate(string op1, string op2, char op) {
    if (op == '+')
        return stoll(op1) + stoll(op2);
    else if (op == '-')
        return stoll(op1) - stoll(op2);
    else if (op == '*')
        return stoll(op1) * stoll(op2);
    return 0;
}

void dfs(int depth) {

    // 연산자 우선순위를 구한 경우
    if (depth == 3) {

        // 주어진 입력 문자열로 연산식을 dq에 저장
        initDq(inStr);  // O(N)
        
        for (int k = 0; k < 3; k++) {   // 3개의 연산자에 대해 차례대로 수행. O(1)
            
            int dqSize = dq.size();
            for (int i = 0; i < dqSize; i++) {  // 연산식에 대해서 계산 수행해서 다시 dq에 삽입. O(N)
                // dq 맨 앞 꺼내기
                string str = dq.front();
                dq.pop_front();

                // 찾는 연산자라면
                if (str.size() < 2 && str[0] == arr[k]) {
                    
                    // 피연산자 하나 더 꺼내기
                    string op2 = dq.front();
                    dq.pop_front();
                    dqSize--;

                    string op1 = dq.back();
                    dq.pop_back();

                    long long result = operate(op1, op2, arr[k]);
                    dq.push_back(to_string(result));
                }
                else {
                    dq.push_back(str);
                }
            }
        }

        long long candi = stoll(dq.front());    // 계산 결과 꺼내기
        dq.pop_front();
        
        if (answer < abs(candi)) answer = abs(candi);   // 정답 갱신

        return;
    }
    for (int i = depth; i < 3; i++) {
        swap(depth, i);
        dfs(depth + 1);
        swap(depth, i);
    }
}

long long solution(string expression) {
    inStr = expression;
    dfs(0); // 연산자 우선순위를 구하기 위한 연산자 우선순위 배열 생성. 3! == O(1)
    return answer;
}

int main() {
    //cout << solution("100-200*300-500+20");
    cout << solution("50*6-3*2");
    //cout << solution("100-200");
    return 0;
}