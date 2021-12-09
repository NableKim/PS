// Time Complexity : O(N * M). N�� ���� ����, M�� cmds ���� 
// N�� �ִ� 1,000,000 �̰� M�� �ִ� 200,000 �̹Ƿ� �ð��ʰ��� �� �� �ۿ� ���µ� �����. �ð� ������ �γ��� �� ����.
// ���Ḯ��Ʈ�� ����, ������ ���� ������ ������ Ž�� �ӵ��� ���� ������ �ִµ�... �� ������ ���Ḯ��Ʈ�� �ذ��Ѵٴ� �� �� ������� ����.

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

    // ���� ���Ḯ��Ʈ ���
    // 0~n-1�� ��� ����, prev, tail ������ ����
    init_Node(n);

    stack<int> st;

    // cmd ��ɾ� �ؼ��ϱ�
    for (string& s : cmd) {
        if (s[0] == 'U') {
            int dis = stoi(s.substr(2));    // �̵��� �Ÿ� ȹ��
            for (int i = 0; i < dis; i++)   k = node[k].prev;
        }
        else if (s[0] == 'D') {
            int dis = stoi(s.substr(2));    // �̵��� �Ÿ� ȹ��
            for (int i = 0; i < dis; i++)   k = node[k].next;
        }
        else if (s[0] == 'C') { // k��° ��带 �����ϱ�
            // ���ÿ� �߰�
            st.push(k);
            
            // k��带 �����ϱ� ���� k-1 ���� k+1 ��带 ���� �̾��ش�
            if (k == head) {      // k ��尡 �� ó���� ���
                head = node[k].next;
                node[node[k].next].prev = -1;   // ���� ����� ���� ��带 ����
                k = node[k].next;               // k�� ���� ��带 ����Ŵ
            } 
            else if (k == tail) { // k ��尡 �� ����� ��� 
                tail = node[k].prev;
                node[node[k].prev].next = -1;   // ���� ����� ������ ��带 ����
                k = node[k].prev;               // k�� ���� ��带 ����Ŵ
            }
            else {                         // �߰� ����� ���
                node[node[k].next].prev = node[k].prev;
                node[node[k].prev].next = node[k].next;
                k = node[k].next;
            }
        }
        else if(s[0] == 'Z') {
            int top = st.top(); st.pop();

            if (node[top].next == head) {      // �����ϴ� ��ġ�� �� ó���̶��
                node[top].prev = -1;
                node[node[top].next].prev = top;
                head = top;
            }
            else if (node[top].prev == tail) { // �� �������̶��
                node[top].next = -1;
                node[node[top].prev].next = top;
                tail = top;
            }
            else {  // �߰��̶��
                node[node[top].prev].next = top;
                node[node[top].next].prev = top;
            }
        }
    }

    // �������� ���� ���Ḯ��Ʈ��� ���� �����
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