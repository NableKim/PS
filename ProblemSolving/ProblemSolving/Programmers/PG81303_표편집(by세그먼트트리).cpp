#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <cstdlib>
#define MAX_ROW_SIZE 1000000

using namespace std;

stack<int> st;              // ������ �� ��ȣ ����
int R[MAX_ROW_SIZE];        // �� ���� ��� ������(index 0���� ����)
int ST[MAX_ROW_SIZE * 4];   // ���׸�Ʈ Ʈ��(index 1���� ����)

// k���� gap��ŭ ���� �ø���
int find_prev(int n, int k, int gap) {
    int cnt = 0;
    while (cnt != gap) {
        if (k - 1 < 0)
            return -1;

        if (R[k - 1])
            cnt++;
        k--;
    }
    return k;
}

// k���� gap��ŭ �Ʒ��� ������
int find_next(int n, int k, int gap) {
    int cnt = 0;
    while (cnt != gap) {
        if (k + 1 >= n)
            return -1;

        if (R[k + 1])
            cnt++;
        k++;
    }
     return k;
}

// node��° ����� ������(start ~ end) ���
int init(int start, int end, int node) {
    if (start == end) return ST[node] = R[start];
    int mid = (start + end) / 2;
    return ST[node] = init(start, mid, node * 2) + init(mid + 1, end, node * 2 + 1);
}

// ������(left, right) ���ϱ�
int sum(int start, int end, int node, int left, int right) {
    if (right < start || end < left) return 0;
    if (left <= start  &&  end <= right) return ST[node];
    int mid = (start + end) / 2;
    return sum(start, mid, node * 2, left, right) + sum(mid + 1, end, node * 2 + 1, left, right);
}

// index��° ��� ������Ʈ
void update(int start, int end, int node, int index, int diff) {
    if (index < start || end < index) return;
    ST[node] += diff;
    if (start == end) return;
    int mid = (start + end) / 2;
    update(start, mid, node * 2, index, diff);
    update(mid+1, end, node * 2+1, index, diff);
}

string solution(int n, int k, vector<string> cmd) {

    // �迭���� 1�� �ʱ�ȭ
    for (int i = 0; i < n; i++) R[i] = 1;

    // ���׸�Ʈ Ʈ�� ����
    init(0, n - 1, 1);

    // ��ɾ� �ؼ� �� ���� ����
    for (string& s : cmd) {
        if (s[0] == 'U') {
            int gap = stoi(s.substr(2));
            int tmp = sum(0, n - 1, 1, k - gap, k - 1);
            k = find_prev(n, k - gap, gap-tmp);
        }
        else if (s[0] == 'D') {
            int gap = stoi(s.substr(2));
            int tmp = sum(0, n - 1, 1, k + 1, k + gap);
            k = find_next(n, k + gap, gap-tmp);
        }
        else if (s[0] == 'C') {
            R[k] = 0;    // �� ���� ó��

            // ������ �� �޸�
            update(0, n - 1, 1, k, -1);
            st.push(k);     

            // ������ ����
            int tmp = find_next(n, k, 1);
            if (tmp < 0)
                k = find_prev(n, k, 1);
            else
                k = tmp;
        }
        else if (s[0] == 'Z') {
            int tmp = st.top();
            R[tmp] = 1;
            update(0, n - 1, 1, tmp, -1);
            st.pop();
        }
    }

    // ���� ����
    string str = "";
    for (int i = 0; i < n; i++) {
        if (R[i])
            str += "O";
        else
            str += "X";
    }

    return str;
}

int main() {

    //cout << solution(8, 2, { "D 2","C","U 3","C","D 4","C","U 2","Z","Z" });
    cout << solution(8, 2, { "D 2","C","U 3","C","D 4","C","U 2","Z","Z","U 1","C" });

}