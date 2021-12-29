#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#define MAX_NUMBER 100000

using namespace std;

struct INFO {
    int idx, cnt;
};

INFO info[MAX_NUMBER + 1];

bool cmp(INFO a, INFO b) {
    return a.cnt > b.cnt;
}

vector<int> solution(string s) {
    vector<int> answer;
    
    for (int i = 0; i < MAX_NUMBER + 1; i++)
        info[i].idx = i;

    int pre = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] >= '0' && s[i] <= '9') {
            pre *= 10;
            pre += (s[i] - '0');
        }
        else {
            if (pre != 0) {
                info[pre].cnt++;
                pre = 0;
            }
        }
    }
    
    sort(info, info + MAX_NUMBER + 1, cmp);

    for (int i = 0; i < MAX_NUMBER + 1; i++) {
        if (info[i].cnt == 0) break;
       answer.push_back(info[i].idx);
    }

    return answer;
}

int main() {

    string str = "{{2},{2,1},{2,1,3},{2,1,3,4}}";
    vector<int> answer = solution(str);

    for (int i = 0; i < answer.size(); i++)
        cout << answer[i] << " ";

    return 0;
}