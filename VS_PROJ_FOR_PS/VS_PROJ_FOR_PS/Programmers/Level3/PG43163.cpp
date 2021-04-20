#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

struct V {
    int idx, dis;
};

int bfs(string begin, string target, vector<string>& words) {

    int visited[51] = { 0, }; // words배열의 idx번째 문자열이 몇번째로 방문했는가
    queue<int> q;
    q.push(words.size() - 1);   // words의 맨 마지막 원소가 시작 노드
    visited[words.size() - 1]=1;  // 시작 노드 방문처리

    

    while (!q.empty()) {
        int front = q.front();
        q.pop();

        if (words[front] == target)
            return visited[front] - 1;

        for (int k = 0; k < words.size()-1; k++) {
            
            // 이미 방문된건 스킵
            if (visited[k] > 0)
                continue;

            string cmp = words[k];

            int diff = 0;
            for (int i = 0; i < cmp.size(); i++) {
                if (cmp[i] != words[front][i])
                    diff++;
            }

            if (diff == 1) {
                q.push(k);
                visited[k] = visited[front]+1;
            }
        }
    }

    return 0;
}

int solution(string begin, string target, vector<string> words) {
    words.push_back(begin);
    return bfs(begin, target, words);
}

int main() {

    //cout << solution("hit", "cog", { "hot", "dot", "dog", "lot", "log", "cog" });
    cout << solution("hit", "cog", { "hot", "dot", "dog", "lot", "log" });


	return 0;
}