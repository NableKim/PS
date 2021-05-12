#include <string>
#include <vector>
#include <map>
#include <iostream>
using namespace std;

vector<int> solution(vector<string> gems) {
    vector<int> answer;
    int ans = 987654321;

    map<string, int> m;
    for (string& s : gems) {
        if (m.find(s) != m.end())
            m[s]++;
        else
            m[s] = 1;
    }

    int n = m.size();   //  보석의 종류 수
    m.clear();

    int l, r;
    l = r = 0;

    m[gems[l]] = 1;

    while (r < gems.size()) {
        // 보석의 수가 다 있다면
        if (m.size() == n) {
            // 현재의 l, r로 구간의 길이 구하기
            if (ans > r - l) {
                ans = r - l;
                answer.clear();
                answer.push_back(l+1);
                answer.push_back(r+1);
            }

            // l 증가 시키기
            if (m[gems[l]] == 1)
                m.erase(gems[l]);
            else
                m[gems[l]]--;
            l++;
        }
        else {
            r++;

            if (r == gems.size())
                break;

            if (m.find(gems[r]) != m.end())
                m[gems[r]]++;
            else
                m[gems[r]] = 1;
        }
    }

    return answer;
}

int main() {

    vector<string> v = { "DIA", "RUBY", "RUBY", "DIA", "DIA", "EMERALD", "SAPPHIRE", "DIA" };

    vector<int> answer = solution(v);

    for (int& a : answer) {
        cout << a << endl;
    }
    
    // map으로 보석의 개수 세기

    // left, right 화살표 만들기
    // left ~ right 사이의 구간을 순회하며
        // 보석의 개수 세기
        // 보석의 개수가 N개라면 L를 하나 증가
            // L과 R 사이의 거리와 정답을 비교 후 더 작으면 answer 배열 갱신
        // 보석의 개수가 N개보다 작으면 R을 증가




    return 0;
}