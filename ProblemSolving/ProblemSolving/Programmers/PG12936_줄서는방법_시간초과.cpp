#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(int n, long long k) {

    vector<int> answer;

    vector<int> v;
    for (int i = 1; i <= n; i++)
        v.push_back(i);

    long long cnt = 0;
    do {
        cnt++;
        if (cnt == k) {
            answer = v;
            break;
        }
    } while (next_permutation(v.begin(), v.end()));

    return answer;
}