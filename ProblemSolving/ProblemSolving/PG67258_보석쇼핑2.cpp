/*
* 시간복잡도 : O(N), N은 gems 배열의 크기
*/

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

unordered_map<string, int> um;
int maxLen = 987654321;


vector<int> solution(vector<string> gems) {
    vector<int> answer;

    // 보석 이름을 key값으로 hash table에 저장. value는 빈도수
    for (string& s : gems)
        um[s]++;

    int jewKind = um.size();    // 보석 종류 수 

    int l, r;
    l = r = 0;

    um.clear();
    um[gems[l]]++;

    // 두 개의 인덱싱 변수로 최소 구간 찾기
    while (r != gems.size()) {

        // 보석 종류를 다 포함하는 구간을 찾았다면
        if (um.size() == jewKind) {
            
            // 구간 길이 측정
            int len = r - l + 1;
            
            // 정답 갱신
            if (maxLen > len) {
                maxLen = len;
                answer.clear();
                answer.push_back(l + 1);
                answer.push_back(r + 1);
            }
            
            // 보석 종류를 다 포함하면서 더 짧은 구간을 탐색하기 위해 l 조정
            um[gems[l]]--;
            if (um[gems[l]] == 0)
                um.erase(gems[l]);
            l++;
        }
        else {
            if (r + 1 == gems.size())
                break;

            um[gems[++r]]++;
        }
    }

    return answer;
}

int main() {

    vector<string> gems = { "A","B","B","B","B","B","B","C","B","A" };
    //vector<string> gems = { "DIA", "RUBY", "RUBY", "DIA", "DIA", "EMERALD", "SAPPHIRE", "DIA" };

    vector<int> results = solution(gems);

    for (int a : results)
        cout << a << " ";
    cout << endl;

    return 0;
}