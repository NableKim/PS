#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

struct P {
    int idx, val;
};

int solution(vector<int> stones, int k) {
    int answer = 200000000;

    // k개의 디딤돌 구간에서 최대값이 있을텐데 그 최대값들 중에 가장 작은 값이 정답임
    deque<P> dq;

    for (int i = 0; i < stones.size(); i++) {

        // 현재 살펴볼 디딤돌보다 k이상 떨어진 디딤돌 값은 제거
        if (!dq.empty() && dq.front().idx <= i - k)
            dq.pop_front();

        // 현재 살펴볼 디딤돌의 값보다 작은 값들은 pop
        while(!dq.empty() && dq.back().val <= stones[i])
            dq.pop_back();
        
        dq.push_back({ i, stones[i] });
        if (i >= k - 1)
            answer = answer > dq.front().val ? dq.front().val : answer;
    }

    return answer;
}


int main() {

    //vector<int> stones = { 6,1,2,5,4,10 };
    //vector<int> stones = { 2, 4, 5, 3, 2, 1, 4, 2, 5, 1 };
    vector<int> stones = { 2, 2 };
    int k = 2;

    cout << solution(stones, k);


	return 0;
}