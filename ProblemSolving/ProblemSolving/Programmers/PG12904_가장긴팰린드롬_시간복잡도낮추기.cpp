// �ð����⵵ : O(N^2)

#include <iostream>
#include <string>
using namespace std;
int solution(string s)
{
    int answer = 1;

    for (int baseIdx = 1; baseIdx < s.size(); baseIdx++) {
        // ¦�� ���ڿ��϶�, Ȧ�� ���ڿ��϶� ���� �� �Ӹ����
        int even = 0, odd = 1;
        bool flag1 = false, flag2 = false;

        for (int k = 1; k <= 2500; k++) {
            int left = baseIdx - k;
            int right = baseIdx + k;

            // ¦�� ���ڿ�
            if (left < 0 || right - 1 >= s.size()) break;

            if (!flag1 && s[left] == s[right - 1]) even += 2;
            else flag1 = true;

            // Ȧ�� ���ڿ�
            if (left < 0 || right >= s.size()) break;

            if (!flag2 && s[left] == s[right]) odd += 2;
            else flag2 = true;

            // ¦��, Ȧ�� ���ڿ� ��� ���̻� �Ӹ������ �� �ʿ䰡 ���ٸ�
            if (flag1 && flag2) break;
        }

        int maxVal = even > odd ? even : odd;
        answer = answer < maxVal ? maxVal : answer;
    }

    return answer;
}