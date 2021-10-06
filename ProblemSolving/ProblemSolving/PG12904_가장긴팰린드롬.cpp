// 시간복잡도 : O(N^3)

#include <iostream>
#include <string>
using namespace std;

int solution(string s)
{
    int sSize = s.size();
    for (int len = sSize; len > 1; len--) {
        for (int start = 0; start <= sSize - len; start++) {
            int left = start;
            int right = start + len - 1;
            bool flag = true;

            while (left < right) {
                if (s[left] != s[right]) {
                    flag = false;
                    break;
                }
                left++;
                right--;
            }

            if (flag)
                return len;
        }
    }

    return 1;
}