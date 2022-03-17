#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

int aCnt;   // ��Ʈ����Ʈ ����
int tCnt;   // Ʃ�� ����
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

        // ���� ���� �ſ� candi�� ������ ���ϴ°� �ִ°�?

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

        // ������ ���� ���
        // ���ݱ��� ���� ������ ������ �����ϴ� ���� ��ŵ

        // �ش� ���յ�� ���ڿ� �ϳ��� �����
        // �� �����ؼ� �ߺ��Ǵ��� Ȯ��
        // �ߺ��Ǵ°�  ������ ���� ����Ʈ�� ����

        return;
    }

    for (int i = depth; i < n; i++) {
        pick.push_back(i);
        nCr(i + 1, n, r, relation);
        pick.pop_back();
    }

}

int solution(vector<vector<string>> relation) {
 
    // 1��~N�� attribute�� ���� ���� ���ϱ�
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