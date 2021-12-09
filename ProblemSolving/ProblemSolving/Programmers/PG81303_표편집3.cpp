// Time Complexity : O(N * M). N은 행의 개수, M은 cmds 개수 
// N은 최대 1,000,000 이고 M은 최대 200,000 이므로 시간초과가 날 수 밖에 없는데 통과함. 시간 제약이 널널한 것 같음.
// 연결리스트는 삽입, 삭제가 빠른 장점이 있지만 탐색 속도가 느린 단점이 있는데... 이 문제를 연결리스트로 해결한다는 게 잘 납득되지 않음.

#include <iostream>
#include <string>
#include <vector>
#include <stack>
#define MAX_NUM 1000000
using namespace std;

typedef struct _Node {
    int prev, next;
} Node;

int head, tail;
Node node[MAX_NUM];

void init_Node(int n) {
    head = 0;
    tail = n - 1;

    for (int i = 0; i < n; i++) {
        node[i].prev = i - 1;
        node[i].next = i + 1;
    }

    node[head].prev = -1;
    node[tail].next = -1;
}

string solution(int n, int k, vector<string> cmd) {

    // 이중 연결리스트 사용
    // 0~n-1번 노드 생성, prev, tail 포인터 생성
    init_Node(n);

    stack<int> st;

    // cmd 명령어 해석하기
    for (string& s : cmd) {
        if (s[0] == 'U') {
            int dis = stoi(s.substr(2));    // 이동할 거리 획득
            for (int i = 0; i < dis; i++)   k = node[k].prev;
        }
        else if (s[0] == 'D') {
            int dis = stoi(s.substr(2));    // 이동할 거리 획득
            for (int i = 0; i < dis; i++)   k = node[k].next;
        }
        else if (s[0] == 'C') { // k번째 노드를 삭제하기
            // 스택에 추가
            st.push(k);
            
            // k노드를 삭제하기 전에 k-1 노드와 k+1 노드를 서로 이어준다
            if (k == head) {      // k 노드가 맨 처음인 경우
                head = node[k].next;
                node[node[k].next].prev = -1;   // 다음 노드의 왼쪽 노드를 비우기
                k = node[k].next;               // k는 다음 노드를 가리킴
            } 
            else if (k == tail) { // k 노드가 끝 노드인 경우 
                tail = node[k].prev;
                node[node[k].prev].next = -1;   // 이전 노드의 오른쪽 노드를 비우기
                k = node[k].prev;               // k는 이전 노드를 가리킴
            }
            else {                         // 중간 노드인 경우
                node[node[k].next].prev = node[k].prev;
                node[node[k].prev].next = node[k].next;
                k = node[k].next;
            }
        }
        else if(s[0] == 'Z') {
            int top = st.top(); st.pop();

            if (node[top].next == head) {      // 삽입하는 위치가 맨 처음이라면
                node[top].prev = -1;
                node[node[top].next].prev = top;
                head = top;
            }
            else if (node[top].prev == tail) { // 맨 마지막이라면
                node[top].next = -1;
                node[node[top].prev].next = top;
                tail = top;
            }
            else {  // 중간이라면
                node[node[top].prev].next = top;
                node[node[top].next].prev = top;
            }
        }
    }

    // 마지막에 남은 연결리스트들로 정답 만들기
    string answer = "";
    for (int i = 0; i < n; i++)
        answer += "X";

    int tmp = head;
    while (tmp != -1) {
        answer[tmp] = 'O';
        tmp = node[tmp].next;
    }

    return answer;
}

int main() {

    //cout << solution(8, 2, { "D 2","C","U 3","C","D 4","C","U 2","Z","Z" });
    cout << solution(8, 2, { "D 2","C","U 3","C","D 4","C","U 2","Z","Z","U 1","C" });

}