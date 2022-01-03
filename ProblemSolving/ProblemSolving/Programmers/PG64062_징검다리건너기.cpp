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

    // k���� ����� �������� �ִ밪�� �����ٵ� �� �ִ밪�� �߿� ���� ���� ���� ������
    deque<P> dq;

    for (int i = 0; i < stones.size(); i++) {

        // ���� ���캼 ��������� k�̻� ������ ����� ���� ����
        if (!dq.empty() && dq.front().idx <= i - k)
            dq.pop_front();

        // ���� ���캼 ������� ������ ���� ������ pop
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