#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;

bool solution(vector<string> phone_book) {
    // 해쉬 만들고
    unordered_map<string, bool> um;

    // key에 value값을 true로 기록
    for (string& s : phone_book)
        um.insert(make_pair(s, true));
    
    int pSize = phone_book.size();
    // 첫번째 문자열부터 짤라내면서 짜른 문자열에 해당하는 value값이 트루면 false 리턴 끝
    for (string& s : phone_book) {
        int sSize = s.size();
        for (int i = 0; i < pSize; i++) {
            string s2 = s.substr(0, i + 1);
            if (um.find(s2) != um.end()) {    // 찾았다면
                if(s2 != s)
                    return false;
            }
        }
    }
    return true;
}

int main() {

    cout << solution({ "123","456","789" });

    return 0;
}