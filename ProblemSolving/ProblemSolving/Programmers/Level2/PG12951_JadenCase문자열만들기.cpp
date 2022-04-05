#include <string>
#include <vector>
using namespace std;

string solution(string s) {

    string answer = s;

    bool flag = true;
    for (int i = 0; i < s.length(); i++) {
        if (flag && s[i] >= 'a' && s[i] <= 'z')
            answer[i] = 'A' + (s[i] - 'a');
        else if (!flag && s[i] >= 'A' && s[i] <= 'Z')
            answer[i] = 'a' + (s[i] - 'A');

        if (s[i] == ' ')
            flag = true;
        else
            flag = false;
    }

    return answer;
}