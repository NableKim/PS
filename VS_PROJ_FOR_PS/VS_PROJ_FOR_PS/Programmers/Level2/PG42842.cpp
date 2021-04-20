#include <cstdio>
#include <vector>
using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;

    for (int r = 5000; r > 0; r--) {

        int c = 0;
        c = (brown + 4 + (-2 * r))/2;

        if (c > r)
            continue;

        if ((c - 2) * (r - 2) == yellow) {
            answer.push_back(r);
            answer.push_back(c);
            break;
        }
    }

    return answer;
}

int main() {

    vector<int> v;
    v = solution(8, 1);

    for (int& a : v) {
        printf("%d ", a);
    }

	return 0;
}