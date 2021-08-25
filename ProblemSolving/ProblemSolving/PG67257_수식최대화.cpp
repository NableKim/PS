#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;

// 0, 1, 2 순열 구하기

char arr[3] = { '+', '-', '*' };
string str;

void swap(int index1, int index2) {
    int tmp = arr[index1];
    arr[index1] = arr[index2];
    arr[index2] = tmp;
}

void dfs(int depth) {
    if (depth == 3) {
        
        // 일단 문자열 하나씩 접근해서 숫자면 이전 숫자에 덧붙이기
        // 연산자가 나오면, 지금 우선순위인 연산자인지 확인
        // 맞으면
            // flag 활성화
            // 다음 숫자를 만들어서 이전 숫자와 연산 후 stack에 넣기, flag 비활성화
        // 다르면 
            // 지금까지 만든 숫자 stack에 넣기
            // 연산자 stack에 넣기

        stack<string> s;
        
        string preNum = "";
        for (int i = 0; i < str.size(); i++) {
            
        }



        return;
    }

    for (int i = depth; i < 3; i++) {
        swap(depth, i);
        dfs(depth + 1);
        swap(depth, i);
    }
}

long long solution(string expression) {
    long long answer = 0;

    // 연산자 우선순위 정하기
    
    str = expression;
    dfs(0);
    

    return answer;
}

int main() {

    cout << solution("100-200*300-500+20");

    return 0;
}