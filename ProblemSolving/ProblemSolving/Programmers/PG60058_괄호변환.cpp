/*
* �ð����⵵ : O(N^2), ���⼭ N�� �־��� ���ڿ��� ���� (N<=1000)
* ��͸� ���� ���� �θ��� Case : )( )( )( )( )( ... �̷������� ������ ��ȣ�� �Է��� ���� ���, 
* ��� Ʈ���� �׷����� ���� ��� �׷���. �׷��ٸ� Ʈ���� ���̴� N/2 �ϰŰ� �� ���� O(N)�̹Ƿ� O(N^2)
*/

#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;

// �־��� ���ڿ��� �ùٸ� ���ڿ����� �Ǵ��ϴ� �Լ�
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

// ���ڿ� �ڵ鸵 �Լ�
string simulation(string s) {

    if (s.empty()) return "";

    // ���ʷ� �������� ���ڿ��� index ã��
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

    // u, v �и�
    string u = s.substr(0, index);      // O(N)
    string v = "";
    if(s.size() != index)
        v = s.substr(index);

    // u�� �ùٸ� ���ڿ��ΰ�?
    if (isCorrect(u)) {
        return u + simulation(v);       // O(N)
    }
    else {
        string tmp = u.substr(1, u.size() - 2); // ù, ������ ����
        string tmp2 = "";
        for (int i = 0; i < tmp.size(); i++) {  // u�� ��ȣ ������
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