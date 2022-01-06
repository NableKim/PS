#include <iostream>
#include <string>
using namespace std;

int solution(string dartResult) {
    int answer = 0;

    int preNumber = 0;
    int number = dartResult[0]-'0';
 
    for (int i=1; i < dartResult.size(); i++) {
        if (dartResult[i] == 'S' || dartResult[i] == 'D' || dartResult[i] == 'T') {
            int add = number;
            int loop = 0;
            if (dartResult[i] == 'D') loop = 1;
            else if (dartResult[i] == 'T') loop = 2;
            
            for (int i = 0; i < loop; i++)
                add *= number;
            number = add;
        }
        else if (dartResult[i] == '*' || dartResult[i] == '#') {
            if (dartResult[i] == '*') {
                answer += preNumber;
                number = (number * 2);
            }
            else {
                number = number * -1;
            }
        }
        else {
            if (dartResult[i-1] >= '0' && dartResult[i - 1] <= '9')
                number = 10;
            else {
                answer += number;
                preNumber = number;
                number = dartResult[i] - '0';
            }
        }
    }
    answer += number;

    return answer;
}

int main() {

    cout << solution("1D2S#10S");

    return 0;
}