/**
* 주어진 주문 내역을 가지고 코스요리를 만들 개수만큼 뽑은 후(조합)
* 지금까지 만들었던 코스요리보다 더 많이 주문되었는지 빈도를 확인 후 정답을 갱신하는 방식
* 시간복잡도 : O(M * N^2 * nCr)
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

#define MAX_ORDER 20                    // orders 최대 크기
#define MAX_STRING_SIZE 11              // orders 한 주문내역의 최대 음식 개수+1

bool O[MAX_ORDER][26];                  // index번째 주문의 음식 정보
int MAX_CNT[MAX_STRING_SIZE];           // index개로 이루어진 메뉴가 최대 몇번 주문되었는가
vector<string> Candi[MAX_STRING_SIZE];  // index개로 이루어진 메뉴들

string s;                               // 조합 때 사용할 기준 문자열
vector<char> pick;                      // 조합 때 사용할 배열
int N;                                  // orders 크기

// char 배열을 string으로 반환해주는 함수
string charToStr(vector<char> v) {
    string s = "";
    for (char& ch : v)
        s += ch;
    return s;
}

// dfs로 조합 생성 함수
void dfs(int depth, int r) {

    // r개 음식을 다 뽑았다면
    if (pick.size() == r) {
        
        // pick한 코스메뉴들이 orders에서 몇번 나왔는가
        int cnt = 0;
        for (int i = 0; i < N; i++) {
            bool flag = true;
            for (int j = 0; j < r; j++) {
                if (O[i][pick[j] - 'A'] == false) {
                    flag = false;   // i번째 주문기록에는 이 코스메뉴가 나오지 않았음
                    break;
                }
            }

            if (flag) cnt++;
        }

        // 2번 이상 나와야 정답 후보
        if (cnt <= 1) return;

        // 지금까지 가장 많이 나온 메뉴면 정답 후보에 추가
        if (MAX_CNT[r] < cnt) {
            Candi[r].clear();   // 기존 정답 후보 배열 초기화
            Candi[r].push_back(charToStr(pick));
            MAX_CNT[r] = cnt;
        }
        else if (MAX_CNT[r] == cnt) {
            Candi[r].push_back(charToStr(pick));
        }

        return;
    }

    for (int i = depth; i < s.size(); i++) {
        pick.push_back(s[i]);
        dfs(i + 1, r);
        pick.pop_back();
    }
}

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;

    N = orders.size();

    // 우선 각 주문별 주문 음식 기록
    for (int i = 0; i < N; i++) {                       // O(N)
        sort(orders[i].begin(), orders[i].end());       // O(NlogN)
        for (int j = 0; j < orders[i].size(); j++)      // O(M)
            O[i][orders[i][j] - 'A'] = true;
    }

    // 첫번째 주문 음식 현황을 갖고 course[]개 만큼 조합 구하기
    for (int i = 0; i < N; i++) {                       // O(N)
        
        // 조합 때 사용할 기준 문자열
        s = orders[i];

        for (int k = 0; k < course.size(); k++)         // O(M)
            dfs(0, course[k]);  // nCr, s 문자열에서 r(== coruse[k])개 문자 뽑기, O(nCr * N)
    }

    // 정답 배열 만들기
    map<string, bool> m;    // 중복 코스요리를 고르기 위해 map 사용
    for (int k = 0; k < course.size(); k++) {           // O(M)
        int index = course[k];
        for (string& str : Candi[index]) {              // O(N)
            if (m.find(str) == m.end()) {               // O(logN)
                m[str] = true;
                answer.push_back(str);
            }
        }
    }

    // 만들어진 코스요리 오름차순 정렬
    sort(answer.begin(), answer.end());

    return answer;
}

int main() {

    vector<string> orders = { "ABCFG", "AC", "CDE", "ACDE", "BCFG", "ACDEH" };
    //vector<string> orders = { "ABCFG"/*, "AC", "CDE", "ACDE", "BCFG", "ACDEH"*/ };
    vector<int> course = { 2,3,4 };

    vector<string> v = solution(orders, course);

    for (string& s : v)
        cout << s << endl;

    return 0;
}