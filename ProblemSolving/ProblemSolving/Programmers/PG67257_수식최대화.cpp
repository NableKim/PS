/*
* �����ڿ� ���� �켱 ������ ������ ���� ��,
* ���� �켱������ ���� ������� ����س��� ����
* �ð����⵵ : O(N^2), N�� �־��� �Է� ���ڿ��� ���� (<=100)
* ���� �־��� ���� �Է� ���ڿ��� "1+2*3*5..." �� ���� �ǿ�����, �����ڰ� ���ڿ� ���� 1���� �����ϴ� �����
*/

#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <cmath>
using namespace std;

char arr[3] = { '+', '-', '*' };    // ������ �켱���� �迭
string inStr;                       // �Է����� �־��� ���ڿ�
deque<string> dq;                   // �־��� ���꿡 ���� ������� ������  dq
long long answer = 0;               // ����

// �־��� �Է� ���ڿ��� ���� dq�� ����� �ʱ� �����ϴ� �Լ�
void initDq(string expression) {

    // dq �ʱ�ȭ
    dq.clear();

    // ������ �켱���� ���ϱ�
    string tmp = "";
    for (int i = 0; i < expression.size(); i++) {
        if (expression[i] >= '0' && expression[i] <= '9')
            tmp += expression[i];
        else {
            dq.push_back(tmp);
            tmp = "";
            tmp += expression[i];
            dq.push_back(tmp);
            tmp = "";
        }
    }
    dq.push_back(tmp); // ex) "100" "-" "200" "*" "300" ... �̷� ������ ����
}

void swap(int index1, int index2) {
    int tmp = arr[index1];
    arr[index1] = arr[index2];
    arr[index2] = tmp;
}

// �����ڿ� ���� ��� �Լ�
long long operate(string op1, string op2, char op) {
    if (op == '+')
        return stoll(op1) + stoll(op2);
    else if (op == '-')
        return stoll(op1) - stoll(op2);
    else if (op == '*')
        return stoll(op1) * stoll(op2);
    return 0;
}

void dfs(int depth) {

    // ������ �켱������ ���� ���
    if (depth == 3) {

        // �־��� �Է� ���ڿ��� ������� dq�� ����
        initDq(inStr);  // O(N)
        
        for (int k = 0; k < 3; k++) {   // 3���� �����ڿ� ���� ���ʴ�� ����. O(1)
            
            int dqSize = dq.size();
            for (int i = 0; i < dqSize; i++) {  // ����Ŀ� ���ؼ� ��� �����ؼ� �ٽ� dq�� ����. O(N)
                // dq �� �� ������
                string str = dq.front();
                dq.pop_front();

                // ã�� �����ڶ��
                if (str.size() < 2 && str[0] == arr[k]) {
                    
                    // �ǿ����� �ϳ� �� ������
                    string op2 = dq.front();
                    dq.pop_front();
                    dqSize--;

                    string op1 = dq.back();
                    dq.pop_back();

                    long long result = operate(op1, op2, arr[k]);
                    dq.push_back(to_string(result));
                }
                else {
                    dq.push_back(str);
                }
            }
        }

        long long candi = stoll(dq.front());    // ��� ��� ������
        dq.pop_front();
        
        if (answer < abs(candi)) answer = abs(candi);   // ���� ����

        return;
    }
    for (int i = depth; i < 3; i++) {
        swap(depth, i);
        dfs(depth + 1);
        swap(depth, i);
    }
}

long long solution(string expression) {
    inStr = expression;
    dfs(0); // ������ �켱������ ���ϱ� ���� ������ �켱���� �迭 ����. 3! == O(1)
    return answer;
}

int main() {
    //cout << solution("100-200*300-500+20");
    cout << solution("50*6-3*2");
    //cout << solution("100-200");
    return 0;
}