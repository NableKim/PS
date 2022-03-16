#include <iostream>
#include <string>
#include <vector>
using namespace std;

void func(int n, int sIdx, int tIdx, int eIdx, vector<vector<int>>& answer) {
    if (n == 1) {
        answer.push_back({ sIdx, eIdx });
        return;
    }

    func(n - 1, sIdx, eIdx, tIdx, answer);
    func(1, sIdx, tIdx, eIdx, answer);
    func(n - 1, tIdx, sIdx, eIdx, answer);
}

vector<vector<int>> solution(int n) {
    vector<vector<int>> answer;
    func(n, 1, 2, 3, answer);
    return answer;
}

int main() {
    solution(2);
}