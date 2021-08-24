/**
* 1 ~ (문자열 길이/2) 단위로 문자열을 잘라 앞의 나온 문자열과 일치하는지 확인해나가는 방식
* 시간 복잡도 : O(N^3), N<1000
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

// 몇자리 숫자인지를 반환하는 함수
int getNumSize(int n) {
    if (n == 1) return 0;
    
    int cnt = 1;
    while (n / 10) {
        cnt++;
        n /= 10;
    }
    return cnt;
}

int solution(string s) {
    int answer = 987654321;
    int sSize = s.size();

    // 비교할 문자열 길이 단위를 1 ~ (s 문자열의 길이 절반)로 늘려가며
    for (int len = 1; len <= sSize / 2; len++) {    // O(N)
        int idx = len, cnt = 1, ansCandidate = 0, lastStrSize = 0;
        string base = s.substr(0, len);             // 비교 기준 문자열

        while (idx < sSize) {                       // O(N)
            
            string cmp = s.substr(idx, len);        // 비교 대상 문자열, O(N)
            lastStrSize = cmp.size();

            if (base == cmp) {                      // 기준 문자열과 비교 대상 문자열이 같으면           
                cnt++;
            }
            else {                                  // 기준 문자열과 비교 대상 문자열이 다르면 
                ansCandidate += len;
                if(cnt>1)                           // 같은 문자열이 2개이상 나왔다면
                    ansCandidate += getNumSize(cnt);
                base = cmp;
                cnt = 1;
            }
            idx += len;
        }
        if (cnt > 1) 
            ansCandidate += getNumSize(cnt);
        ansCandidate += lastStrSize;
        answer = answer > ansCandidate ? ansCandidate : answer; // 정답 갱신
    }

    if (answer == 987654321)
        answer = 1;

    return answer;
}

int main() {

    string s = "aabb";
    cout << solution(s);

    return 0;
}