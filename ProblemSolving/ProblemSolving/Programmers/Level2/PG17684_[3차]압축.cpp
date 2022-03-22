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
    int s = 0, e = 0;

    while (s < msg.length()) {

        int cnt = 0;
        bool flag = true;
        for (int e = s; e < msg.length(); e++) {
            string substr = msg.substr(s, e - s + 1);

            // �������� �ʴ� ��Ȳ�̶��
            if (um[substr] == 0) {
                string pre_substr = msg.substr(s, e - s);
                answer.push_back(um[pre_substr]);
                um[substr] = ++indexCnt;    // ���ο� �ܾ ������ �߰�
                flag = false;
                break;
            }
            else
                cnt++;
        }

        if (flag) {
            string pre_substr = msg.substr(s);
            answer.push_back(um[pre_substr]);
        }

        s += cnt;
    }


    return answer;
}