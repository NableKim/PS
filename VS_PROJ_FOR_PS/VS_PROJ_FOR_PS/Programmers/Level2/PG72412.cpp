#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

vector<int> db[3][2][2][2];

vector<int> parse_info(string s) {
    vector<int> v;
    string temp = "";
    for (char& c : s) {
        if (c == ' ') {
            if (temp == "cpp"
                || temp == "backend"
                || temp == "junior"
                || temp == "chicken")
                v.push_back(0);
            else if (temp == "python")
                v.push_back(2);
            else
                v.push_back(1);
            temp = "";
        }
        else 
            temp += c;
    }
    v.push_back(stoi(temp));
    return v;
}

vector<int> parse_query(string s) {
    vector<int> v;
    string temp = "";
    for (char& c : s) {
        if (c == ' ') {
            if (temp == "-")
                v.push_back(-1);
            if (temp == "cpp"
                || temp == "backend"
                || temp == "junior"
                || temp == "chicken")
                v.push_back(0);
            else if (temp == "python")
                v.push_back(2);
            if (temp == "java"
                || temp == "frontend"
                || temp == "senior"
                || temp == "pizza")
                v.push_back(1);
            temp = "";
        }
        else
           temp += c;
    }
    v.push_back(stoi(temp));
    return v;
}

int binary_search(vector<int> v, int value) {

    int left = 0, right = v.size() - 1;

    while (left <= right) {
        int mid = (left + right) / 2;

        if (v[mid] < value)
            left = mid+1;
        else if (v[mid] >= value)
            right = mid-1;
    }

    return left;
}

vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> answer;
    
    // info 정보를 4차원 배열로 담기 >> 5만
    for (string& s : info) {
        vector<int> v = parse_info(s);
        db[v[0]][v[1]][v[2]][v[3]].push_back(v[4]);
    }

    // 4차원 배열에 담긴 점수값을 오름차순으로 정렬
    for (int x = 0; x < 3; x++)
        for (int y = 0; y < 2; y++)
            for (int z = 0; z < 2; z++)
                for (int f = 0; f < 2; f++)
                        sort(db[x][y][z][f].begin(), db[x][y][z][f].end());

    // query문 분석
    for (string& s : query) {
        vector<int> v = parse_query(s);
        int lan = v[0], pos = v[1], rank = v[2], food = v[3];
        
        int xs, xe, ys, ye, zs, ze, fs, fe;

        if (lan == -1) {
            xs = 0; xe = 2;
        }
        else
            xs = xe = lan;

        if (pos == -1) {
            ys = 0; ye = 1;
        }
        else
            ys = ye = pos;

        if (rank == -1) {
            zs = 0; ze = 1;
        }
        else
            zs = ze = rank;

        if (food == -1) {
            fs = 0; fe = 1;
        }
        else
            fs = fe = food;

        // 4중 구문으로 query문에 부합하는 숫자 누적 합 구하기
        // X점 이상이 시작되는 인덱스 구하기 >> index
        // 배열 갯수 - index >> 정답에 추가
        int sum = 0;
        for (int x = xs; x <= xe; x++) {
            for (int y = ys; y <= ye; y++) {
                for (int z = zs; z <= ze; z++) {
                    for (int f = fs; f <= fe; f++) {
                        int index = binary_search(db[x][y][z][f],v[4]);
                        sum += db[x][y][z][f].size() - index;
                    }
                }
            }
        }
        answer.push_back(sum);
    }
    
    return answer;
}

int main() {
    vector<int> v = solution(
        { 
            "java backend junior pizza 150",
            "python frontend senior chicken 210",
            "python frontend senior chicken 150",
            "cpp backend senior pizza 260",
            "java backend junior chicken 80",
            "python backend senior chicken 50" 
        },
        { 
            "java and backend and junior and pizza 100", 
            "python and frontend and senior and chicken 200", 
            "cpp and - and senior and pizza 250", 
            "- and backend and senior and - 150", 
            "- and - and - and chicken 100", 
            "- and - and - and - 150" 
        });
    for (int& a : v)
        cout << a << " ";
}