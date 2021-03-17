#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <algorithm>
using namespace std;

bool cmp(string& a, string& b) {
    return a.size() < b.size();
}

vector<int> solution(string s) {
    // s를 {} 없애버리고
    // s를 } 단위로 잘라서
    // vector<string> 에 저장
    // 길이 짧은 순서로 정렬

    // 문자열에서 숫자 추출
    // 숫자를 키로 한 해쉬값이 존재하지 않으면 정답에 추가

    string s2 = s.substr(1, s.size()-2);
    
    vector<string> v;
    int index = 0;  // } 다음 지점
    for (int i = 0; i < s2.size(); i++) {
        if (s2[i] == '}') {
            v.push_back(s2.substr(index, i-index+1));
            index = i + 2;
        }
    }

    sort(v.begin(), v.end(), cmp);

    vector<int> answer;
    unordered_map<int, bool> um;
    for (string& s3 : v) {
        int num = 0;
        for (int i = 0; i < s3.size(); i++) {
            if (s3[i] >= '0' && s3[i] <='9') {
                num *= 10;
                num += (s3[i] - '0');
            }
            else if (s3[i] == ',' || s3[i] == '}') {
                if (um.find(num) == um.end()) {
                    um.insert(make_pair(num, true));
                    answer.push_back(num);
                }
                num = 0;
            }
        }
    }
    
    return answer;
}

int main() {

    vector<int> v = solution("{{2},{2,1},{2,1,3},{2,1,3,4}}");

    for (int& a : v)
        cout << a << " ";

    return 0;
}