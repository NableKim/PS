#include <string>
#include <vector>
#include <cmath>
#include <iostream>
using namespace std;

struct POINT {
    int y, x;
};

POINT P[12];

void init() {
    P[0] = { 3, 1 };
    P[1] = { 0, 0 };
    P[2] = { 0, 1 };
    P[3] = { 0, 2 };
    P[4] = { 1, 0 };
    P[5] = { 1, 1 };
    P[6] = { 1, 2 };
    P[7] = { 2, 0 };
    P[8] = { 2, 1 };
    P[9] = { 2, 2 };
    P[10] = { 3, 0 };
    P[11] = { 3, 2 };
}

string solution(vector<int> numbers, string hand) {
    string answer = "";

    init();

    // 현재 손가락 위치
    int lx = 0, ly = 3;
    int rx = 2, ry = 3;

    for (int& n : numbers) {
        if (n % 3 == 2 || n == 0) {
            int n1 = abs(P[n].y - ly) + abs(P[n].x - lx);
            int n2 = abs(P[n].y - ry) + abs(P[n].x - rx);

            if (n1 < n2) {
                answer += "L";
                ly = P[n].y;
                lx = P[n].x;
            }
            else if (n1 > n2) {
                answer += "R";
                ry = P[n].y;
                rx = P[n].x;
            }
            else {
                if (hand[0] == 'r') {
                    answer += "R";
                    ry = P[n].y;
                    rx = P[n].x;
                }
                else {
                    answer += "L";
                    ly = P[n].y;
                    lx = P[n].x;
                }
            }
        }
        else if (n % 3 == 1) {
            answer += "L";
            ly = P[n].y;
            lx = P[n].x;
        }
        else if (n % 3 == 0) {
            answer += "R";
            ry = P[n].y;
            rx = P[n].x;
        }
    }

    return answer;
}