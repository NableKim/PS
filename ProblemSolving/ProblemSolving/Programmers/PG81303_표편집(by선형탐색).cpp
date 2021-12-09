#include <iostream>
#include <string>
#include <vector>
#include <stack>
#define MAX_ROW_SIZE 1000000

using namespace std;

stack<int> st;          // 삭제된 행 번호 저장
bool R[MAX_ROW_SIZE];   // false : 존재

// k에서 gap만큼 위로 올리기
int find_prev(int n, int k, int gap) {
    int cnt = 0;
    while (cnt != gap) {
        if (k - 1 < 0)
            return -1;

        if (!R[k - 1]) 
            cnt++;
        k--;
    }
    return k;
}

// k에서 gap만큼 아래로 내리기
int find_next(int n, int k, int gap) {
    int cnt = 0;
    while (cnt != gap) {
        if (k + 1 >= n)
            return -1;

        if (!R[k + 1])
            cnt++;
        k++;
    }
    return k;
}

string solution(int n, int k, vector<string> cmd) {

    // 명령어 해석 및 동작 수행
    for (string& s : cmd) {
        if (s[0] == 'U') {
            int gap = stoi(s.substr(2));
            k = find_prev(n, k, gap);
        }
        else if (s[0] == 'D') {
            int gap = stoi(s.substr(2));
            k = find_next(n, k, gap);
        }
        else if (s[0] == 'C') {
            R[k] = true;    // 행 삭제 처리

            st.push(k);     // 삭제된 행 메모
            
            // 다음행 선택
            int tmp = find_next(n, k, 1);
            if (tmp < 0)
                k = find_prev(n, k, 1);
            else
                k = tmp;
        }
        else if (s[0] == 'Z') {
            R[st.top()] = false;
            st.pop();
        }
    }

    // 정답 생성
    string str = "";
    for (int i = 0; i < n; i++) {
        if (R[i])
            str += "X";
        else
            str += "O";
    }

    return str;
}

int main() {

    cout << solution(8, 2, { "D 2","C","U 3","C","D 4","C","U 2","Z","Z" });

}