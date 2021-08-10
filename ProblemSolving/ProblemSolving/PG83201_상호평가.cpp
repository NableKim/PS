// 시간복잡도 : O(N^2), N은 학생 수

#include <iostream>
#include <string>
#include <vector>
using namespace std;

string getGrade(int sum) {
    if (sum >= 90)
        return "A";
    else if (sum >= 80)
        return "B";
    else if (sum >= 70)
        return "C";
    else if (sum >= 50)
        return "D";
    else
        return "F";
}

string solution(vector<vector<int>> scores) {
    string answer = "";
    
    // 이 학생의 본인 평가 점수를 메모
    // 한 학생의 최고점, 최저점 값을 구하기
    // 이 학생의 본인 평가 점수와 동일한게 몇개인지 카운팅
    // 최고, 최저점에서 같은게 나왔고 그게 본인 평가 점수만 존재하는거라면 평균에서 제외

    int N = scores.size();
    for (int x = 0; x < N; x++) {

        int self = scores[x][x];    // 본인 평가 점수
        int cnt = 0;                // 본인 평가 점수와 동일한 점수
        int max = -1;               // 최고점
        int min = 1000;             // 최저점
        int sum = 0;                // 평가 점수 총 합계

        for (int y = 0; y < N; y++) {
            // 본인 평가 점수와 동일한 점수 개수
            if (scores[y][x] == self)
                cnt++;

            // 최대값 계산
            if (max < scores[y][x])
                max = scores[y][x];

            // 최소값 계산
            if (min > scores[y][x])
                min = scores[y][x];
        
            sum += scores[y][x];
        }

        if ((max == self || min == self) && cnt == 1) {
            sum -= self;
            sum /= N-1;
        }
        else
            sum /= N;

        answer += getGrade(sum);
    }
    
    return answer;
}

int main() {

    cout << solution({ {50,90},{50,87} });


    return 0;
}