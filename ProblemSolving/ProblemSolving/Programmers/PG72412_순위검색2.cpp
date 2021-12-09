/*
* 주어진 query에 대해 빠르게 카운팅할 수 있는 자료구조가 필요하여 hash 구조 사용
* 시간복잡도 : O(NlogN). N은 Info 개수
*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

unordered_map<string, vector<int>> um;

vector<string> parsing(string str) {
    vector<string> tmp;
    int index = -1;
    for (int i = 0; i < str.size(); i++) {
        if (str[i] == ' ') {
            index++;
            string s_tmp = str.substr(index, i - index);
            tmp.push_back(s_tmp);
            index = i;
        }
    }
    index++;
    tmp.push_back(str.substr(index));
    return tmp;
}

void make_db(int bitNum, vector<string> tmp) {
    string str = "";
    for (int i = 0; i < 4; i++)
        str += (bitNum & (1 << i)) ? "-" : tmp[i];  // ex) -Backend-Pizza
    um[str].push_back(stoi(tmp[4]));
}

int getLowerBound(string key, int target) {

    int left = 0;
    int right = um[key].size() - 1;

    while (left < right) {
        int mid = (left + right) >> 1;

        if (um[key][mid] >= target)
            right = mid;
        else
            left = mid + 1;
    }

    return right;
}

vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> answer;

    um.clear();

    // 주어진 info 정보를 hash 자료구조를 사용하여 db 만들기
    for (string& str : info) {                      // O(N)
        vector<string> tmp = parsing(str);          // O(info 하나의 최대 문자열 길이)

        // 0000 ~ 1111
        for (int i = 0; i < 16; i++)
            make_db(i, tmp);
    }
    
    // 동일한 key 값을 가지는 점수들에 대하여 오름차순 정렬
    unordered_map<string, vector<int>>::iterator it;
    for (it = um.begin(); it != um.end(); it++)     // O(NlogN)
        sort(it->second.begin(), it->second.end());
    
    for (string& str : query) {                     // O(M)
        vector<string> tmp = parsing(str);          // O(query 하나의 최대 문자열 길이)

        // query로 key 생성
        string key = "";
        key = tmp[0] + tmp[2] + tmp[4] + tmp[6];

        // tmp[7] score값 이상인 구간이 최초로 발견되는 부분 찾기
        // lowerbound를 하기 앞서 맨 뒤에값 비교
        int index = um[key].size();
        if(index > 0 && stoi(tmp[7]) <= um[key][index-1])
            index = getLowerBound(key, stoi(tmp[7])); // O(logN)

        answer.push_back(um[key].size() - index);
    }

    return answer;
}

int main() {

    vector<string> info = { "java backend junior pizza 150", "python frontend senior chicken 210", "python frontend senior chicken 150", "cpp backend senior pizza 260", "java backend junior chicken 80", "python backend senior chicken 50" };
    //vector<string> qeury = { "java and backend and junior and pizza 100","python and frontend and senior and chicken 200","cpp and - and senior and pizza 250","- and backend and senior and - 150","- and - and - and chicken 100","- and - and - and - 150" };
    vector<string> qeury = { "- and - and - and - 3000"};

    vector<int> answer = solution(info, qeury);

    for (int a : answer)
        cout << a << " ";
    cout << endl;


    return 0;
}