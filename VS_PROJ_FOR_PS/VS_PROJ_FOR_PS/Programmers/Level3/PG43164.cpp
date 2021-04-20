#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool flag;

void dfs(string startLoc, vector<vector<string>>& tickets, vector<bool>& useCheck, vector<string>& path, int useCnt, vector<string>& answer) {
    
    if (flag)
        return;

    if (useCnt == tickets.size()) {
        answer = path;
        flag = true;
        return;
    }

    for (int i = 0; i < tickets.size(); i++) {
        // 출발지가 같고 사용하지 않은 티켓이라면
        if (startLoc == tickets[i][0] && !useCheck[i]) {
            useCheck[i] = true;
            path.push_back(tickets[i][1]);  // 여정에 포함시키기
            dfs(tickets[i][1], tickets, useCheck, path, useCnt + 1, answer);
            path.pop_back();    // 되돌리기
            useCheck[i] = false;
        }
    }
}

vector<string> solution(vector<vector<string>> tickets) {
    
    vector<string> answer;
    vector<bool> useCheck(tickets.size(), false);
    vector<string> path;
    path.push_back("ICN");  // 출발지
    int useCnt = 0; // 사용한 티켓 개수
    sort(tickets.begin(), tickets.end());
    dfs("ICN", tickets, useCheck, path, useCnt, answer);
    
    return answer;
}

int main() {
    //vector<vector<string>> tickets = { {"ICN", "JFK"}, { "HND", "IAD" }, { "JFK", "HND" }};
    vector<vector<string>> tickets = { {"ICN", "SFO"},{"ICN", "ATL"},{"SFO", "ATL"},{"ATL", "ICN"},{"ATL", "SFO"} };
    vector<string> answer = solution(tickets);

    for (string& s : answer)
        cout << s << "\n";

    return 0;
}