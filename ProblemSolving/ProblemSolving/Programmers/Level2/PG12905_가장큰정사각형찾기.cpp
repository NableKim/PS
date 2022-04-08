#include <vector>
using namespace std;

int min(int a, int b) {
    return a < b ? a : b;
}

int solution(vector<vector<int>> board)
{
    int maxVal = 0;
    for (int y = 1; y < board.size(); y++) {
        for (int x = 1; x < board[0].size(); x++) {
            if (board[y][x] == 0) continue;
            int left = board[y][x - 1];
            int diagonal = board[y - 1][x - 1];
            int right = board[y - 1][x];

            board[y][x] = min(left, min(diagonal, right)) + 1;
            maxVal = maxVal < board[y][x] ? board[y][x] : maxVal;
        }
    }

    if (maxVal == 0) {
        for (int x = 0; x < board[0].size(); x++) {
            maxVal = maxVal < board[0][x] ? board[0][x] : maxVal;
        }
        for (int y = 0; y < board.size(); y++) {
            maxVal = maxVal < board[y][0] ? board[y][0] : maxVal;
        }
    }

    return maxVal * maxVal;
}