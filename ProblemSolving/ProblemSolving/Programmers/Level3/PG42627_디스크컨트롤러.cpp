#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

struct INFO {
    int s, w;
};

priority_queue<INFO> pq;

bool operator<(INFO a, INFO b) {
    if (a.w == b.w) {
        return a.s > b.s;
    }
    return a.w > b.w;
}

int solution(vector<vector<int>> jobs) {
    int answer = 0;

    sort(jobs.begin(), jobs.end());

    int t = 0;
    int index = 0;
    int jSize = jobs.size();
    while (1) {
        if (index == jSize && pq.empty())
            break;

        // 현재 시간을 기준으로 작업에 들어갈 수 있는 대상을 힙에 넣기
        for (index; index < jSize; index++) {
            int s = jobs[index][0];
            int w = jobs[index][1];

            if (s > t)
                break;

            pq.push({ s, w });
        }

        if (pq.empty()) {
            if(index < jSize)
                t = jobs[index][0];
            continue;
        }

        INFO target = pq.top();
        pq.pop();
        t += target.w;
        answer += (t - target.s);
    }

    return answer/jSize;
}

int main() {

    cout << solution({ {0,3},{1,9},{2,6} });

    return 0;
}