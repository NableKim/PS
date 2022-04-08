#include <string>
#include <vector>
using namespace std;

vector<int> answer(2, 0);

void func(int sy, int sx, int len, vector<vector<int>>& arr) {

    if (len == 1)
        return;

    // 전 면적 확인
    int initValue = arr[sy][sx];
    bool flag = true;
    for (int y = sy; y < sy + len; y++) {
        for (int x = sx; x < sx + len; x++) {
            if (initValue != arr[y][x]) {
                flag = false;
                break;
            }
        }
        if (!flag) break;
    }

    if (flag) {
        answer[initValue] -= (len * len);
        answer[initValue]++;
        return;
    }

    func(sy, sx, len / 2, arr);
    func(sy, sx + len / 2, len / 2, arr);
    func(sy + len / 2, sx, len / 2, arr);
    func(sy + len / 2, sx + len / 2, len / 2, arr);
}

vector<int> solution(vector<vector<int>> arr) {

    for (int y = 0; y < arr.size(); y++) {
        for (int x = 0; x < arr.size(); x++) {
            answer[arr[y][x]]++;
        }
    }

    func(0, 0, arr.size(), arr);

    return answer;
}