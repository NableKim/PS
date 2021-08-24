/**
* �־��� �ֹ� ������ ������ �ڽ��丮�� ���� ������ŭ ���� ��(����)
* ���ݱ��� ������� �ڽ��丮���� �� ���� �ֹ��Ǿ����� �󵵸� Ȯ�� �� ������ �����ϴ� ���
* �ð����⵵ : O(M * N^2 * nCr)
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

#define MAX_ORDER 20                    // orders �ִ� ũ��
#define MAX_STRING_SIZE 11              // orders �� �ֹ������� �ִ� ���� ����+1

bool O[MAX_ORDER][26];                  // index��° �ֹ��� ���� ����
int MAX_CNT[MAX_STRING_SIZE];           // index���� �̷���� �޴��� �ִ� ��� �ֹ��Ǿ��°�
vector<string> Candi[MAX_STRING_SIZE];  // index���� �̷���� �޴���

string s;                               // ���� �� ����� ���� ���ڿ�
vector<char> pick;                      // ���� �� ����� �迭
int N;                                  // orders ũ��

// char �迭�� string���� ��ȯ���ִ� �Լ�
string charToStr(vector<char> v) {
    string s = "";
    for (char& ch : v)
        s += ch;
    return s;
}

// dfs�� ���� ���� �Լ�
void dfs(int depth, int r) {

    // r�� ������ �� �̾Ҵٸ�
    if (pick.size() == r) {
        
        // pick�� �ڽ��޴����� orders���� ��� ���Դ°�
        int cnt = 0;
        for (int i = 0; i < N; i++) {
            bool flag = true;
            for (int j = 0; j < r; j++) {
                if (O[i][pick[j] - 'A'] == false) {
                    flag = false;   // i��° �ֹ���Ͽ��� �� �ڽ��޴��� ������ �ʾ���
                    break;
                }
            }

            if (flag) cnt++;
        }

        // 2�� �̻� ���;� ���� �ĺ�
        if (cnt <= 1) return;

        // ���ݱ��� ���� ���� ���� �޴��� ���� �ĺ��� �߰�
        if (MAX_CNT[r] < cnt) {
            Candi[r].clear();   // ���� ���� �ĺ� �迭 �ʱ�ȭ
            Candi[r].push_back(charToStr(pick));
            MAX_CNT[r] = cnt;
        }
        else if (MAX_CNT[r] == cnt) {
            Candi[r].push_back(charToStr(pick));
        }

        return;
    }

    for (int i = depth; i < s.size(); i++) {
        pick.push_back(s[i]);
        dfs(i + 1, r);
        pick.pop_back();
    }
}

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;

    N = orders.size();

    // �켱 �� �ֹ��� �ֹ� ���� ���
    for (int i = 0; i < N; i++) {                       // O(N)
        sort(orders[i].begin(), orders[i].end());       // O(NlogN)
        for (int j = 0; j < orders[i].size(); j++)      // O(M)
            O[i][orders[i][j] - 'A'] = true;
    }

    // ù��° �ֹ� ���� ��Ȳ�� ���� course[]�� ��ŭ ���� ���ϱ�
    for (int i = 0; i < N; i++) {                       // O(N)
        
        // ���� �� ����� ���� ���ڿ�
        s = orders[i];

        for (int k = 0; k < course.size(); k++)         // O(M)
            dfs(0, course[k]);  // nCr, s ���ڿ����� r(== coruse[k])�� ���� �̱�, O(nCr * N)
    }

    // ���� �迭 �����
    map<string, bool> m;    // �ߺ� �ڽ��丮�� ���� ���� map ���
    for (int k = 0; k < course.size(); k++) {           // O(M)
        int index = course[k];
        for (string& str : Candi[index]) {              // O(N)
            if (m.find(str) == m.end()) {               // O(logN)
                m[str] = true;
                answer.push_back(str);
            }
        }
    }

    // ������� �ڽ��丮 �������� ����
    sort(answer.begin(), answer.end());

    return answer;
}

int main() {

    vector<string> orders = { "ABCFG", "AC", "CDE", "ACDE", "BCFG", "ACDEH" };
    //vector<string> orders = { "ABCFG"/*, "AC", "CDE", "ACDE", "BCFG", "ACDEH"*/ };
    vector<int> course = { 2,3,4 };

    vector<string> v = solution(orders, course);

    for (string& s : v)
        cout << s << endl;

    return 0;
}