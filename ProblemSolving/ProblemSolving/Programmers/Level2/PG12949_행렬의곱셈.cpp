#include <string>
#include <vector>
using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    vector<vector<int>> answer;

    int row = arr1.size();
    int col = arr2[0].size();
    int len = arr1[0].size();

    for (int r = 0; r < row; r++) {
        vector<int> tmp;
        for (int c = 0; c < col; c++) {
            int sum = 0;
            for (int l = 0; l < len; l++)
                sum += arr1[r][l] * arr2[l][c];
            tmp.push_back(sum);
        }
        answer.push_back(tmp);
    }

    return answer;
}