#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;

// 0, 1, 2 ���� ���ϱ�

char arr[3] = { '+', '-', '*' };
string str;

void swap(int index1, int index2) {
    int tmp = arr[index1];
    arr[index1] = arr[index2];
    arr[index2] = tmp;
}

void dfs(int depth) {
    if (depth == 3) {
        
        // �ϴ� ���ڿ� �ϳ��� �����ؼ� ���ڸ� ���� ���ڿ� �����̱�
        // �����ڰ� ������, ���� �켱������ ���������� Ȯ��
        // ������
            // flag Ȱ��ȭ
            // ���� ���ڸ� ���� ���� ���ڿ� ���� �� stack�� �ֱ�, flag ��Ȱ��ȭ
        // �ٸ��� 
            // ���ݱ��� ���� ���� stack�� �ֱ�
            // ������ stack�� �ֱ�

        stack<string> s;
        
        string preNum = "";
        for (int i = 0; i < str.size(); i++) {
            
        }



        return;
    }

    for (int i = depth; i < 3; i++) {
        swap(depth, i);
        dfs(depth + 1);
        swap(depth, i);
    }
}

long long solution(string expression) {
    long long answer = 0;

    // ������ �켱���� ���ϱ�
    
    str = expression;
    dfs(0);
    

    return answer;
}

int main() {

    cout << solution("100-200*300-500+20");

    return 0;
}