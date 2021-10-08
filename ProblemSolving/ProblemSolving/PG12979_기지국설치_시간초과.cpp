// 시간복잡도 : O(N)

#include <iostream>
#include <vector>
using namespace std;

int map[200000002];

int solution(int n, vector<int> stations, int w)
{
    int answer = 0;

    for (int& st : stations) {
        int start = st - w;
        int end = st + w;

        if (start < 1)
            start = 1;

        if (end > n)
            end = n;

        map[start]++;
        map[end + 1]--;
    }

    for (int i = 1; i <= n; i++) {
        map[i] += map[i - 1];
    }

    int left = 0;
    bool flag = false;
    for (int i = 1; i <= n; i++) {
        if (map[i] == 0 && !flag) {
            flag = true;
            left = i;
        }

        if (map[i] > 0 && flag) {
            flag = false;
            int len = i - left;
            int q = len / (2 * w + 1);
            if (len % (2 * w + 1) != 0)
                q++;
            answer += q;
        }
    }

    if (flag) {
        int len = n - left + 1;
        int q = len / (2 * w + 1);
        if (len % (2 * w + 1) != 0)
            q++;
        answer += q;
    }

    return answer;
}