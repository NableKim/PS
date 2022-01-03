#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

vector<int> banList[8];
vector<int> pick;
unordered_map<int, bool> um;
int answer;

void comb(int depth, int N, bool* check) {
    if (pick.size() == N) {

        vector<int> tmp = pick;
        sort(tmp.begin(), tmp.end());

        int key = 0;
        for (int i = 0; i < N; i++) {
            key *= 10;
            key += tmp[i];
        }

        if (um[key] == false) {
            um[key] = true;
            answer++;
        }

        return;
    }

    for (int i = 0; i < banList[depth].size(); i++) {
        if (check[banList[depth][i]]) continue;
        pick.push_back(banList[depth][i]);
        check[banList[depth][i]] = true;
        comb(depth + 1, N, check);
        pick.pop_back();
        check[banList[depth][i]] = false;
    }
}

int solution(vector<string> user_id, vector<string> banned_id) {
 
    for (int i = 0; i < banned_id.size(); i++) {
        string banStr = banned_id[i];
        for (int j = 0; j < user_id.size(); j++) {
            string userStr = user_id[j];

            if (userStr.size() != banStr.size()) continue;
            bool flag = true;
            for (int k = 0; k < userStr.size(); k++) {
                if (banStr[k] == '*') continue;
                if (banStr[k] != userStr[k]) {
                    flag = false;
                    break;
                }
            }
            if (flag)
                banList[i].push_back(j);
        }
    }

    bool check[8] = { false, };
    comb(0, banned_id.size(), check);

    return answer;
}

int main() {

    vector<string> user_id = { "frodo", "fradi", "crodo", "abc123", "frodoc" };
    vector<string> banned_id = { "fr*d*", "*rodo", "******", "******" };

    cout << solution(user_id, banned_id);

    return 0;
}