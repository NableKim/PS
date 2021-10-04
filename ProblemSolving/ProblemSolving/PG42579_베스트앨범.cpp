// 시간복잡도 : O(N*M*logN). N은 genres배열 갯수, M은 장르 종류 수

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

    // 해시테이블에 장르별 재생횟수 데이터 저장
    // Hash[key] = [ {-1, 총 재생횟수}, {idx, cnt}, {idx, cnt}, ...]
    for (int i = 0; i < genres.size(); i++) {           // O(N)
        // 새로운 장르이면
        if (um.find(genres[i]) == um.end())
            um[genres[i]].push_back({ -1, 0 });
        
        // 장르명을 Key로 id, 재생횟수를 Value로 삽입
        um[genres[i]].push_back({ i, plays[i] });
        um[genres[i]][0].cnt += plays[i];   // 재생횟수 가산
    }

    // 장르별 총 재생횟수값 추출
    vector<N> v;
    unordered_map<string, vector<P>>::iterator it;
    for (it = um.begin(); it != um.end(); it++) {      // O(M)
        // 장르별 총 재생횟수를 vector에 삽입
        v.push_back({ it->first, (it->second)[0].cnt });
        
        // 같은 장르에서는 재생 횟수를 기준으로 내림차순 정렬
        sort(um[it->first].begin(), um[it->first].end(), cmpP);     // O(N * logN)
    }

    // 내림차순 정렬
    sort(v.begin(), v.end(), cmpN);

    // 한 장르 내에서 가장 많이 재생한 노래 idx 추출
    for (int i = 0; i < v.size(); i++) {            // O(M)
        int num = um[v[i].genre].size();    // 해당 장르의 노래 수
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