/**
* 1 ~ (���ڿ� ����/2) ������ ���ڿ��� �߶� ���� ���� ���ڿ��� ��ġ�ϴ��� Ȯ���س����� ���
* �ð� ���⵵ : O(N^3), N<1000
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

// ���ڸ� ���������� ��ȯ�ϴ� �Լ�
int getNumSize(int n) {
    if (n == 1) return 0;
    
    int cnt = 1;
    while (n / 10) {
        cnt++;
        n /= 10;
    }
    return cnt;
}

int solution(string s) {
    int answer = 987654321;
    int sSize = s.size();

    // ���� ���ڿ� ���� ������ 1 ~ (s ���ڿ��� ���� ����)�� �÷�����
    for (int len = 1; len <= sSize / 2; len++) {    // O(N)
        int idx = len, cnt = 1, ansCandidate = 0, lastStrSize = 0;
        string base = s.substr(0, len);             // �� ���� ���ڿ�

        while (idx < sSize) {                       // O(N)
            
            string cmp = s.substr(idx, len);        // �� ��� ���ڿ�, O(N)
            lastStrSize = cmp.size();

            if (base == cmp) {                      // ���� ���ڿ��� �� ��� ���ڿ��� ������           
                cnt++;
            }
            else {                                  // ���� ���ڿ��� �� ��� ���ڿ��� �ٸ��� 
                ansCandidate += len;
                if(cnt>1)                           // ���� ���ڿ��� 2���̻� ���Դٸ�
                    ansCandidate += getNumSize(cnt);
                base = cmp;
                cnt = 1;
            }
            idx += len;
        }
        if (cnt > 1) 
            ansCandidate += getNumSize(cnt);
        ansCandidate += lastStrSize;
        answer = answer > ansCandidate ? ansCandidate : answer; // ���� ����
    }

    if (answer == 987654321)
        answer = 1;

    return answer;
}

int main() {

    string s = "aabb";
    cout << solution(s);

    return 0;
}