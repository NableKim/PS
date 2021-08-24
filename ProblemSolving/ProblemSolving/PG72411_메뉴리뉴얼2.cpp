/**
* �־��� �ֹ� ������ ������ �ڽ��丮�� ���� ������ŭ ���� ��(����)
* ���ݱ��� ������� �ڽ��丮���� �� ���� �ֹ��Ǿ����� �󵵸� Ȯ�� �� ������ �����ϴ� ��� with unorder_map
* �ð����⵵ : O(N^6)
*/

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

vector<string> cv[11][21];      // y���� ���ĵ��� x�� �ֹ��� �ڽ��丮���� ���� �迭
unordered_map<string, int> um;  // key �ڽ��丮�� ��� �ֹ��Ǿ��°�
int MAX_CNT[11];                // index���� �������� �̷���� �ڽ��丮�� �ִ� ��� ���Դ°�
string order;

// ���� �� �ִ� ��� ������ ���켭 �ڽ��丮 �ֹ� Ƚ���� ī��Ʈ
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

    // order���� ������ ���� �� �ִ� ������ �� ���
    for (string& s : orders) {              // O(N)
        sort(s.begin(), s.end());           // O(MlogM)
        order = s;
        dfs(0, "");                         // O(N^5)
    }

    // ������� �ڽ��丮�� ���� ������ ���� ���� ����
    for(int &k : course) {                  // O(M)
        if (MAX_CNT[k] <= 1) continue;

        vector<string>& v = cv[k][MAX_CNT[k]];
        
        for (int i = 0; i < v.size(); i++)  // O(N}
            answer.push_back(v[i]);
    }

    // �������� ����
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