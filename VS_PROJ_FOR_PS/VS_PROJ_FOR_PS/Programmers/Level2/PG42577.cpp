#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <algorithm>
using namespace std;

bool cmp(string& a, string& b) {
    return a.size() > b.size();
}

bool solution(vector<string> phone_book) {
    // 사전 순으로 정렬
    sort(phone_book.begin(), phone_book.end(), cmp);

    // key에 value값을 true로 기록
    unordered_map<string, bool> um;

    // 첫번째 문자열부터 짤라내면서 짜른 문자열에 해당하는 value값이 트루면 false 리턴 끝
    for (string& s : phone_book) {
        if (um.find(s) != um.end())    // 찾았다면
            return false;

        int sSize = s.size();
        for (int i = 0; i < sSize; i++) {
            string s2 = s.substr(0, i + 1);
            um.insert(make_pair(s2, true));
        }
    }
    return true;
}

int main() {

    cout << solution({ "119", "97674223", "1195524421" });

    return 0;
}