#include <string>
#include <stack>
using namespace std;

int solution(string s) {
    int answer = 0;
    int sLen = s.length();

    s += s;

    // 몇번 이동할 것인가
    for (int k = 0; k < sLen; k++) {

        stack<char> st;

        // k부터 sLen 까지의 구간
        bool flag = true;
        for (int i = k; i < sLen + k; i++) {

            if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
                st.push(s[i]);
            }
            else {
                if (st.empty()) {
                    flag = false;
                    break;
                }

                if (s[i] == ')' && st.top() == '(') st.pop();
                else if (s[i] == ']' && st.top() == '[') st.pop();
                else if (s[i] == '}' && st.top() == '{') st.pop();
            }

        }

        if (flag && st.empty()) answer++;
    }

    return answer;
}