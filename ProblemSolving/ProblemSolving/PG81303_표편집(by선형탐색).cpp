#include <iostream>
#include <string>
#include <vector>
#include <stack>
#define MAX_ROW_SIZE 1000000

using namespace std;

stack<int> st;          // ������ �� ��ȣ ����
bool R[MAX_ROW_SIZE];   // false : ����

// k���� gap��ŭ ���� �ø���
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

// k���� gap��ŭ �Ʒ��� ������
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

    // ��ɾ� �ؼ� �� ���� ����
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
            R[k] = true;    // �� ���� ó��

            st.push(k);     // ������ �� �޸�
            
            // ������ ����
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

    // ���� ����
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