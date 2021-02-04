#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> citations);
bool cmp(const int& a, const int& b);

int main() {
    vector<int> citations = { 3, 0, 6, 1, 5 };
    printf("%d", solution(citations));
	return 0;
}

bool cmp(const int &a, const int &b) {
    return a > b;
}

int solution(vector<int> citations) {
    int answer = 0;

    // 내림차순으로 정렬을 해두자
    sort(citations.begin(), citations.end(), cmp);
    
    // 제일 큰 수부터 살피는데
    int cSize = citations.size();
    for (int h = citations[0]; h >= 0; h--)
    {
        int cnt = 0;
        for (int j = 0; j < cSize; j++) {
            if (h <= citations[j])
                cnt++;
            else
                break;
        }

        if (cnt >= h) {
            answer = h;
            break;
        }
    }

    return answer;
}