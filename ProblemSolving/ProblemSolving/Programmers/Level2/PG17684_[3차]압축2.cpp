#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

unordered_map<string, int> um;

vector<int> solution(string msg) {
    vector<int> answer;

    // ���� ���� �ʱ�ȭ
    for (int i = 0; i < 26; i++) {
        string str = "";
        str += 'A' + i;
        um[str] = i + 1;
    }

    int indexCnt = 26;
    int idx = 0;
    string str = "";
    while (idx < msg.length()) {
        // ���ο� ���ڸ� �߰����ְ�
        str += msg[idx];

        // ������ �������� �ʴ´ٸ�
        if (um[str] == 0) {
            um[str] = ++indexCnt;
            str.pop_back();
            answer.push_back(um[str]);
            str = "";
        }
        else
            idx++;
    }

    if (!str.empty())
        answer.push_back(um[str]);

    return answer;
}