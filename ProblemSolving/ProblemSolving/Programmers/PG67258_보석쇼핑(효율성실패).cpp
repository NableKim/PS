#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

unordered_map<string, int> um;

vector<int> solution(vector<string> gems) {
    vector<int> answer;

    for (string& s : gems)
        um[s]++;

    int jewKind = um.size();    // 보석 종류 수

    for (int l = jewKind; l <= gems.size(); l++) {
        
        unordered_map<string, int> umm;

        int start = 0;
        int end = start + l - 1;

        for (int i = start; i <= end; i++)
            umm[gems[i]]++;

        if (umm.size() == jewKind) {
            answer.push_back(start+1);
            answer.push_back(end+1);
            break;
        }

        bool flag = false;
        while (end < gems.size() -1) {

            umm[gems[start]]--;
            if (umm[gems[start]] == 0)
                umm.erase(gems[start]);
            
            start++; end++;

            umm[gems[end]]++;
            if (umm.size() == jewKind) {
                answer.push_back(start + 1);
                answer.push_back(end + 1);
                flag = true;
                break;
            }
        }
        
        if (flag)
            break;
    }

    return answer;
}

int main() {

    vector<string> gems = { "A","B","B","B","B","B","B","C","B","A" };
    //vector<string> gems = { "DIA", "RUBY", "RUBY", "DIA", "DIA", "EMERALD", "SAPPHIRE", "DIA" };

    vector<int> results = solution(gems);

    for (int a : results)
        cout << a << " ";
    cout << endl;

    return 0;
}