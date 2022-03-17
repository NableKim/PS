#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

int aCnt;   // 어트리뷰트 갯수
int tCnt;   // 튜플 갯수
vector<int> pick;
vector<vector<int>> candi;

bool aIsBelongToB(vector<int> a, vector<int> b) {

    int cnt = 0;
    for (int i = 0; i < a.size(); i++) {
        for (int j = 0; j < b.size(); j++) {
            if (a[i] == b[j]) {
                cnt++;
                break;
            }
        }
    }

    if (a.size() == cnt) return true;
    return false;

}

void nCr(int depth, int n, int r, vector<vector<string>>& relation) {

    if (pick.size() == r) {

        // 지금 뽑은 거에 candi가 완전히 속하는게 있는가?

        bool flag = false;
        for (int i = 0; i < candi.size(); i++) {
            if (aIsBelongToB(candi[i], pick))
                return;
        }

        unordered_map<string, bool> um;
        
        for (int k = 0; k < tCnt; k++) {
            string str = "";
            for (int i = 0; i < r; i++) {
                int idx = pick[i];
                str += relation[k][idx];
            }

            if (um[str])
                return;
            else
                um[str] = true;
        }
        
        candi.push_back(pick);       

        // 조합을 구한 경우
        // 지금까지 구한 정답을 온전히 포함하는 경우는 스킵

        // 해당 조합들로 문자열 하나를 만들기
        // 맵 구성해서 중복되는지 확인
        // 중복되는게  없으면 정답 리스트에 포함

        return;
    }

    for (int i = depth; i < n; i++) {
        pick.push_back(i);
        nCr(i + 1, n, r, relation);
        pick.pop_back();
    }

}

int solution(vector<vector<string>> relation) {
 
    // 1개~N개 attribute를 고르는 조합 구하기
    aCnt = relation[0].size();
    tCnt = relation.size();
    for (int i = 1; i <= aCnt; i++) {
        nCr(0, aCnt, i, relation);
    }

    return candi.size();
}

int main() {

    test();

    vector<vector<string>> relations = { {"100","ryan","music","2"},{"200","apeach","math","2"},{"300","tube","computer","3"},{"400","con","computer","4"},{"500","muzi","music","3"},{"600","apeach","music","2"} };

    cout << solution(relations);

    return 0;
}