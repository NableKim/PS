#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

const char charSet[5] = { 'A', 'E', 'I', 'O', 'U' };
vector<string> v;
unordered_map<string, int> um;

void dfs(string str) {

    if (str.length() > 5) return;

    v.push_back(str);

    for (int i = 0; i < 5; i++) {
        str += charSet[i];
        dfs(str);
        str.pop_back();
    }
}

int solution(string word) {
    int answer = 0;

    dfs("");

    sort(v.begin(), v.end());

    for (int i = 0; i < v.size(); i++) {
        um[v[i]] = i;
    }

    answer = um[word];

    return answer;
}

int main() {

    return 0;
}