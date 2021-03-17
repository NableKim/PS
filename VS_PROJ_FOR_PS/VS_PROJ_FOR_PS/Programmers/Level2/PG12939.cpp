#include <string>
#include <vector>
#include <iostream>
using namespace std;

string solution(string s) {
    string answer = "";
    
    int mx=-987654321, mi= 987654321;
    bool flag = false;  // 음수인가
    int num = 0;
    for (char& c : s) {
        if (c == '-') {
            flag = true;
        }
        else if(c >= '0' && c <= '9') {
            num *= 10;
            num += c - '0';
        }
        else {
            if (flag)
                num *= -1;
            mx = mx < num ? num : mx;
            mi = mi > num ? num : mi;
            flag = false;
            num = 0;
        }
    }

    // 마지막 수에 대해서
    if (flag)
        num *= -1;
    mx = mx < num ? num : mx;
    mi = mi > num ? num : mi;

    answer = to_string(mi) + " " + to_string(mx);
    return answer;
}

int main() {
    cout << solution("-1 -1");
    
    return 0;
}