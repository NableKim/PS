/*
* 시간복잡도 : O(N^2), 여기서 N은 주어진 문자열의 길이 (N<=1000)
* 재귀를 가장 많이 부르는 Case : )( )( )( )( )( ... 이런식으로 엇갈린 괄호로 입력이 들어온 경우, 
* 재귀 트리를 그렸을때 가장 깊게 그려짐. 그렇다면 트리의 높이는 N/2 일거고 한 노드당 O(N)이므로 O(N^2)
*/

#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;

// 주어진 문자열이 올바른 문자열인지 판단하는 함수
bool isCorrect(string s) {
    if (s.empty()) return true;

    stack<char> stack;
    stack.push(s[0]);
    for (int i = 1; i < s.size(); i++) {        // O(N)
        if (s[i] == ')' && stack.top() == '(') {
            stack.pop();
        }
        else {
            stack.push(s[i]);
        }
    }

    if (stack.empty())
        return true;
    return false;
}

// 문자열 핸들링 함수
string simulation(string s) {

    if (s.empty()) return "";

    // 최초로 균형잡힌 문자열인 index 찾기
    int left = 0, right = 0, index =0;
    for (; index < s.size(); index++) { // O(N)
        if (s[index] == '(')
            left++;
        else
            right++;

        if (left == right)
            break;
    }

    if (index < s.size())
        index++;

    // u, v 분리
    string u = s.substr(0, index);      // O(N)
    string v = "";
    if(s.size() != index)
        v = s.substr(index);

    // u가 올바른 문자열인가?
    if (isCorrect(u)) {
        return u + simulation(v);       // O(N)
    }
    else {
        string tmp = u.substr(1, u.size() - 2); // 첫, 끝문자 제거
        string tmp2 = "";
        for (int i = 0; i < tmp.size(); i++) {  // u의 괄호 뒤집기
            if (tmp[i] == '(')
                tmp2 += ")";
            else
                tmp2 += "(";
        }
        return "(" + simulation(v) + ")" + tmp2;
    }
}

string solution(string p) {
    return simulation(p);
}

int main() {

    //cout << solution("(()())()");
    //cout << solution(")(");
    cout << solution("()))((()");

    return 0;
}