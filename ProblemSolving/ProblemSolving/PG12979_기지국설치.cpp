// 시간복잡도 : O(N)

#include <vector>
using namespace std;

int map[200000002];

int getIncreasement(int len, int w) {
    int q = len / (2 * w + 1);
    if (len % (2 * w + 1) != 0)
        q++;
    return q;
}

int solution(int n, vector<int> stations, int w)
{
    int answer = 0;

    // 1번 아파트 ~ 첫번째 기지국 사이의 전파가 통하지 않는 구간
    int len = 0;
    if (stations[0] - w > 1) {
        len = stations[0] - w - 1;
        answer += getIncreasement(len, w);
    }

    // 첫번째 기지국과 마지막 기지국 사이의 전파가 통하지 않는 구간
    for (int i = 0; i < stations.size() - 1; i++) {
        int left = stations[i] + w + 1;
        int right = stations[i + 1] - w - 1;

        if (left > right) continue;

        len = right - left + 1;
        answer += getIncreasement(len, w);
    }

    // 마지막 기지국과 n번째 아파트 사이의 전파가 통하지 않는 구간
    if (stations[stations.size() - 1] + w < n) {
        len = n - (stations[stations.size() - 1] + w);
        answer += getIncreasement(len, w);
    }

    return answer;
}