#include <iostream>
#include <string>
#include <vector>
using namespace std;

int R[11];
int A[11];
int AN[11];
int maxDiff;

void comb(int depth, int n) {

    if (n == 0) {

        int scoreA = 0;
        int scoreR = 0;

        // 승부 결정 짓기
        for (int i = 0; i < 11; i++) {
            if (A[i] == 0 && R[i] == 0)
                continue;

            if (R[i] <= A[i])
                scoreA += (10 - i);
            else
                scoreR += (10 - i);
        }

        int diff = scoreR - scoreA;
        if (diff < maxDiff) return;
        
        if (maxDiff == diff) {
            bool ch = false;
            for (int i = 10; i >= 0; i--) {
                if (AN[i] < R[i]) {
                    ch = true;
                    break;
                }
                else if (AN[i] > R[i])
                    break;
            }

            if (!ch) return;  
        }

        maxDiff = diff;
        for (int i = 0; i < 11; i++)
            AN[i] = R[i];

        return;
    }

    if (depth >= 11) return;

    for (int i = n; i >= 0; i--) {
        R[depth] = i;
        comb(depth + 1, n - i);
        R[depth] = 0;
    }
}


vector<int> solution(int n, vector<int> info) {
    vector<int> answer;

    // 어피키 점수 전역화
    for (int i = 0; i < 11; i++)
        A[i] = info[i];

    // 0~9까지 수 중에서 n개 뽑는 조합 구하기
    comb(0, n);

    // 정답 찾기
    if (maxDiff == 0)
        answer.push_back(-1);
    else {
        for (int i = 0; i < 11; i++)
            answer.push_back(AN[i]);
    }

    return answer;
}

int main() {

    vector<int> answer = solution(1, { 1,0,0,0,0,0,0,0,0,0,0 });
    for (int i = 0; i < answer.size(); i++)
        cout << answer[i] << " ";

    return 0;
}