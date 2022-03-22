#include <string>
#include <vector>
using namespace std;

vector<int> solution(int n, long long left, long long right) {
    vector<int> answer;

    for (long long i = left; i <= right; i++) {
        long long q = i / n;
        long long r = i % n;
        q++;
        r++;

        if (q > r)
            answer.push_back(q);
        else
            answer.push_back(r);
    }

    return answer;
}