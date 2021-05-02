#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

string solution(string new_id) {

    // 소문자 치환, 허용되지 않은 문자 버리기
    string str = "";
    for (char& c : new_id) {
        if (c >= 'A' && c <= 'Z') {
            str += c - 'A' + 'a';
        }
        else if (((c >= 'a' && c <= 'z')
            || c == '.'
            || (c >= '0' && c <= '9')
            || c == '-'
            || c == '_'
            || c == '.'))
            str += c;
    }

    bool flag = false;
    new_id = "";
    for (char& c : str) {
        if (c == '.' )
            flag = true;
        else {
            if (flag) {
                new_id += '.';
                flag = false;
            }
            new_id += c;
        }
    }

    if (new_id[0] == '.')
        new_id = new_id.substr(1, new_id.size() - 1);
    if (new_id[new_id.size()-1] == '.')
        new_id = new_id.substr(0, new_id.size() - 1);

    if (new_id.size() == 0)
        new_id += "a";

    if (new_id.size() >= 16) {
        new_id = new_id.substr(0, 15);
        if (new_id[new_id.size() - 1] == '.')
            new_id = new_id.substr(0, new_id.size() - 1);
    }

    while (new_id.size() <= 2) {
        new_id += new_id[new_id.size() - 1];
    }

    return new_id;
}

int main() {

    cout << solution("...!@BaT#*..y.abcdefghijklm");

    return 0;
}