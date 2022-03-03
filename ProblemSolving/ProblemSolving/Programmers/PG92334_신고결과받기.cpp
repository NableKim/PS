#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

unordered_map<string, int> idIndexMap;

bool R[1000][1000];
int C[1000];
int A[1000];

int getSpaceIdx(string str) {
    int idx = 0;
    while (str[idx] != ' ')
        idx++;
    return idx;
}

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer;

    // id별 index를 부여
    for (int i = 0; i < id_list.size(); i++) {
        idIndexMap[id_list[i]] = i;
    }

    // 신고 기록 파싱
    for (int i = 0; i < report.size(); i++) {

        int spaceIdx = getSpaceIdx(report[i]);

        int who = idIndexMap[report[i].substr(0, spaceIdx)];
        int obj = idIndexMap[report[i].substr(spaceIdx+1)];

        if (R[who][obj]) continue;
        R[who][obj] = true;
        C[obj]++;
    }

    for (int i = 0; i < id_list.size(); i++) {
        if (C[i] >= k) {
            for (int j = 0; j < id_list.size(); j++) {
                if (R[j][i])
                    A[j]++;
            }
        }
    }

    for (int i = 0; i < id_list.size(); i++)
        answer.push_back(A[i]);
    
    return answer;
}

int main() {

    vector<string> id_list = { "muzi", "frodo", "apeach", "neo" };
    vector<string> report = { "muzi frodo","apeach frodo","frodo neo","muzi neo","apeach muzi" };
    int k = 2;

    vector<int> answer = solution(id_list, report, k);

    for (int i = 0; i < answer.size(); i++)
        cout << answer[i];

    return 0;
}