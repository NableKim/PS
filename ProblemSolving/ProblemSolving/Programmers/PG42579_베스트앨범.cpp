// �ð����⵵ : O(N*M*logN). N�� genres�迭 ����, M�� �帣 ���� ��

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

struct P {
    int idx, cnt;
};

struct N {
    string genre;
    int cnt;
};

bool cmpP(P a, P b) {
    return a.cnt > b.cnt;
}

bool cmpN(N a, N b) {
    return a.cnt > b.cnt;
}

unordered_map<string, vector<P>> um;

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;

    // �ؽ����̺� �帣�� ���Ƚ�� ������ ����
    // Hash[key] = [ {-1, �� ���Ƚ��}, {idx, cnt}, {idx, cnt}, ...]
    for (int i = 0; i < genres.size(); i++) {           // O(N)
        // ���ο� �帣�̸�
        if (um.find(genres[i]) == um.end())
            um[genres[i]].push_back({ -1, 0 });
        
        // �帣���� Key�� id, ���Ƚ���� Value�� ����
        um[genres[i]].push_back({ i, plays[i] });
        um[genres[i]][0].cnt += plays[i];   // ���Ƚ�� ����
    }

    // �帣�� �� ���Ƚ���� ����
    vector<N> v;
    unordered_map<string, vector<P>>::iterator it;
    for (it = um.begin(); it != um.end(); it++) {      // O(M)
        // �帣�� �� ���Ƚ���� vector�� ����
        v.push_back({ it->first, (it->second)[0].cnt });
        
        // ���� �帣������ ��� Ƚ���� �������� �������� ����
        sort(um[it->first].begin(), um[it->first].end(), cmpP);     // O(N * logN)
    }

    // �������� ����
    sort(v.begin(), v.end(), cmpN);

    // �� �帣 ������ ���� ���� ����� �뷡 idx ����
    for (int i = 0; i < v.size(); i++) {            // O(M)
        int num = um[v[i].genre].size();    // �ش� �帣�� �뷡 ��
        if (num > 3) num = 3;

        for (int j = 1; j < num; j++)               // O(2)
            answer.push_back(um[v[i].genre][j].idx);
    }

    return answer;
}

int main() {

    vector<string> genres = { "classic", "pop", "classic", "classic", "pop" };
    vector<int> plays = { 500, 600, 150, 800, 2500 };
    
    vector<int> answer = solution(genres, plays);
    for (int& a : answer)
        cout << a << " ";

}