/**
* 주어진 주문 내역을 가지고 코스요리를 만들 개수만큼 뽑은 후(조합)
* 지금까지 만들었던 코스요리보다 더 많이 주문되었는지 빈도를 확인 후 정답을 갱신하는 방식 with unorder_map
* 시간복잡도 : O(N^6)
*/

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

vector<string> cv[11][21];      // y개의 음식들이 x번 주문된 코스요리들을 담을 배열
unordered_map<string, int> um;  // key 코스요리가 몇번 주문되었는가
int MAX_CNT[11];                // index개의 음식으로 이루어진 코스요리가 최대 몇번 나왔는가
string order;

// 나올 수 있는 모든 조합을 구헤서 코스요리 주문 횟수를 카운트
void dfs(int depth, string food) {
    int fSize = food.length();
    if (fSize > 0) {
        um[food]++;
        MAX_CNT[fSize] = max(MAX_CNT[fSize], um[food]);
        cv[fSize][um[food]].push_back(food);
    }

    for (int i = depth; i < order.length(); i++) {
        food.push_back(order[i]);
        dfs(i + 1, food);
        food.pop_back();
    }
}

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;

    // order들을 가지고 만들 수 있는 조합을 다 기록
    for (string& s : orders) {              // O(N)
        sort(s.begin(), s.end());           // O(MlogM)
        order = s;
        dfs(0, "");                         // O(N^5)
    }

    // 만드려는 코스요리의 음식 갯수에 따라 정답 도출
    for(int &k : course) {                  // O(M)
        if (MAX_CNT[k] <= 1) continue;

        vector<string>& v = cv[k][MAX_CNT[k]];
        
        for (int i = 0; i < v.size(); i++)  // O(N}
            answer.push_back(v[i]);
    }

    // 오름차순 정렬
    sort(answer.begin(), answer.end());

    return answer;
}

int main() {

    vector<string> orders = { "ABCFG", "AC", "CDE", "ACDE", "BCFG", "ACDEH" };
    vector<int> course = { 2,3,4 };

    vector<string> v = solution(orders, course);

    for (string& s : v)
        cout << s << endl;

    return 0;
}