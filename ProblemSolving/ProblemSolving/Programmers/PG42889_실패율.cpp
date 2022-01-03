#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#define MAX_NUM 500

using namespace std;


struct INFO {
    int num;
    double fail;
};

int cnt[MAX_NUM + 1];
int sum[MAX_NUM + 1];

vector<INFO> v;

//

bool operator <(INFO a, INFO b) {
    return a.fail > b.fail;
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    
    for (int i = 0; i < stages.size(); i++) 
        cnt[stages[i]]++;

    sum[0] = cnt[0];
    for (int i = 1; i <= N+1; i++)
        sum[i] = cnt[i] + sum[i - 1];
    
    int total = sum[N + 1];
    for (int i = 1; i <= N; i++) {

        int pass = total - sum[i-1];

        if(pass == 0)
            v.push_back({ i,0.0 });
        else {
            double fail = (double)cnt[i] / (double)pass;
            v.push_back({ i, fail });
        }
    }

    sort(v.begin(), v.end());
    
    for (int i = 0; i < v.size(); i++)
        answer.push_back(v[i].num);
    
    return answer;
}

int main() {

    //solution(5, { 2, 1, 2, 6, 2, 4, 3, 3 });
    solution(4, { 4,4,4,4,4 });

    return 0;
}