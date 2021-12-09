/*
* �ð����⵵ : O(N), N�� gems �迭�� ũ��
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

    // ���� �̸��� key������ hash table�� ����. value�� �󵵼�
    for (string& s : gems)
        um[s]++;

    int jewKind = um.size();    // ���� ���� �� 

    int l, r;
    l = r = 0;

    um.clear();
    um[gems[l]]++;

    // �� ���� �ε��� ������ �ּ� ���� ã��
    while (r != gems.size()) {

        // ���� ������ �� �����ϴ� ������ ã�Ҵٸ�
        if (um.size() == jewKind) {
            
            // ���� ���� ����
            int len = r - l + 1;
            
            // ���� ����
            if (maxLen > len) {
                maxLen = len;
                answer.clear();
                answer.push_back(l + 1);
                answer.push_back(r + 1);
            }
            
            // ���� ������ �� �����ϸ鼭 �� ª�� ������ Ž���ϱ� ���� l ����
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