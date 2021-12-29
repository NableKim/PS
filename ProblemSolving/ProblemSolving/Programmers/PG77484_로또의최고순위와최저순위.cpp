#include <iostream>
#include <string>
#include <vector>

#define MAX_NUMBER 45

using namespace std;

bool check[MAX_NUMBER + 1];


vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;

    for (int i = 0; i < win_nums.size(); i++)
        check[win_nums[i]] = true;
    
    int cnt = 0;
    int zero = 0;
    for (int i = 0; i < lottos.size(); i++) {
        if (lottos[i] != 0 && check[lottos[i]])
            cnt++;
        else if (lottos[i] == 0)
            zero++;
    }

    int rank = 6;
    if (cnt >= 2)
        rank -= (cnt - 1);

    answer.push_back(rank - zero);
    answer.push_back(rank);

    return answer;
}

int main() {

    vector<int> lottos = { 44, 1, 0, 0, 31, 25 };
    vector<int> win_num = { 31, 10, 45, 1, 6, 19 };

    vector<int> ans = solution(lottos, win_num);
    cout << ans[0] << " " << ans[1];

    return 0;
}