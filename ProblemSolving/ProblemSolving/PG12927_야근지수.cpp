// �ð����⵵ : O(N+M). N�� �־��� �ð� n, M�� works ������ ũ��

#include <string>
#include <vector>
#include <queue>
using namespace std;

priority_queue<int> pq;

long long solution(int n, vector<int> works) {
    long long answer = 0;

    for (int i = 0; i < works.size(); i++)   // O(M)
        pq.push(works[i]);

    for (int i = 0; i < n; i++) {            // O(N)

        if (pq.empty())
            continue;

        int top = pq.top();
        pq.pop();

        if (top >= 1) {
            top--;
            pq.push(top);
        }
    }


    while (!pq.empty()) {
        int top = pq.top();
        pq.pop();
        answer += (top * top);
    }

    return answer;
}