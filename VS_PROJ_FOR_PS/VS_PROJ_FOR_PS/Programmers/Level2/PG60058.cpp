#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string flipStr(string s) {
    if (s.empty())
        return "";

    int sSize = 0;
    string s2 = "";
    for (int i = 0; i < sSize; i++)
    {
        if (s[i] == '(')
            s2 += ")";
        else
            s2 += "(";
    }
    return s2;
}

bool isCorrect(string s) {
    int a = 0;
    int sSize = s.size();
    for (int i = 0; i < sSize; i++)
    {
        if (s[i] == '(')
            a++;
        else
            a--;

        // 비균형 괄호 문자열인 경우
        if (a < 0)
            return false;
    }
    return true;

}

string solution(string p) {
    if (p.empty())
        return "";

    if (isCorrect(p))
        return p;

    // 최초로 균형잡힌 최소 문자열을 잘라내기
    int pSize = p.size();
    int cnt = 0;
    int i = 0;
    for (; i < pSize; i++) {
        if (p[i] == '(')
            cnt++;
        else
            cnt--;
        
        if (cnt == 0)
            break;
    }

    // i번째 인덱스 전까지가 최소 균형잡힌 문자열임
    string u = p.substr(0, i+1);
    string v = "";
    if(i+1 != pSize)
        v = p.substr(i+1);
    
    // u가 올바른 괄호 문자열인가
    if (isCorrect(u))
        return u + solution(v);
    else {
        string temp = u.substr(1, i - 1);   // 맨 앞/뒤 문자열 제거
        return  "(" + solution(v) + ")"+ flipStr(temp);
    }
}

int main() {
    string str = "()))((()";
    cout << solution(str);
}
