#include <string>
#include <vector>

using namespace std;

vector<long long> solution(vector<long long> numbers) {
    vector<long long> answer;

    for (long long& number : numbers) {

        if (number % 2 == 0) {
            answer.push_back(number + 1);
            continue;
        }

        // Ȧ���� ���, ���ӵ� 1�� ���� ����
        long long tmp = number;
        long long cnt = 0;
        while (tmp & 1) {
            tmp >>= 1;
            cnt++;
        }

        number += 1LL << (cnt - 1);
        answer.push_back(number);
    }


    return answer;
}