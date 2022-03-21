#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

unordered_map<string, bool> um;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;


    char preEndChar = words[0][0];
    int index = 0;
    for (string& s : words) {
        if (s.length() == 1) break;
        else if (preEndChar != s[0]) break;
        else if (um[s]) break;

        um[s] = true;
        preEndChar = s[s.length() - 1];
        index++;
    }

    if (index == words.size()) {
        answer.push_back(0);
        answer.push_back(0);
        return answer;
    }

    answer.push_back(index % n + 1);
    answer.push_back(index / n + 1);

    return answer;
}