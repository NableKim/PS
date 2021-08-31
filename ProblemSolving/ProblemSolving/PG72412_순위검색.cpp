/*
*   ## 아이디어
*    1. info 문자열에서 주어진 데이터들을 파싱
*    2. 정제된 지원자 정보 배열에 저장
*    3. 점수를 기준으로 정렬
*    4. query문을 읽고
*    5. query 문에서도 공백을 기준으로 데이터 뽑아내고
*    6. 원하는 점수 이상인 구간 인덱스를 찾고 거기서부터 탐색 시작
* 정확도 점수는 100점이나 효율성에서 시간 초과
* 시간복잡도 : O(N*M). N은 Info 개수, M은 query 개수
*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct S {
    string lang, pos, level, food;
    int score;
};

vector<S> db;

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

bool cmp(S a, S b) {
    return a.score < b.score;
}

int getLowerBound(int left, int right, int target) {

    while (left < right) {
        int mid = (left + right) >> 1;
        
        if (db[mid].score < target)
            left = mid + 1;
        else
            right = mid;
    }

    return right;
}

vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> answer;

    for (string& str : info) {
        vector<string> tmp = parsing(str);

        db.push_back({ 
            tmp[0], 
            tmp[1] , 
            tmp[2], 
            tmp[3], 
            stoi(tmp[4])
        });
    }

    sort(db.begin(), db.end(), cmp);

    for (string& str : query) { // O(M)
        vector<string> tmp = parsing(str);

        // tmp[7] score값 이상인 구간이 최초로 발견되는 부분 찾기
        int index = getLowerBound(0, db.size(), stoi(tmp[7]));  // O(logN)

        int cnt = 0;
        for (int i = index; i < db.size(); i++) {   // O(N)
            
            // 언어 비교
            if (tmp[0][0] != '-' && db[i].lang[0] != tmp[0][0])
                continue;

            // 직군 비교
            if (tmp[2][0] != '-' && db[i].pos[0] != tmp[2][0])
                continue;

            // 경력 비교
            if (tmp[4][0] != '-' && db[i].level[0] != tmp[4][0])
                continue;

            // 음식 비교
            if (tmp[6][0] != '-' && db[i].food[0] != tmp[6][0])
                continue;

            cnt++;
        }

        answer.push_back(cnt);
    }


    return answer;
}

int main() {

    vector<string> info = {"java backend junior pizza 150", "python frontend senior chicken 210", "python frontend senior chicken 150", "cpp backend senior pizza 260", "java backend junior chicken 80", "python backend senior chicken 50"};
    vector<string> qeury = { "java and backend and junior and pizza 100","python and frontend and senior and chicken 200","cpp and - and senior and pizza 250","- and backend and senior and - 150","- and - and - and chicken 100","- and - and - and - 150" };

    vector<int> answer = solution(info, qeury);

    for (int a : answer)
        cout << a << " ";
    cout << endl;
    

    return 0;
}