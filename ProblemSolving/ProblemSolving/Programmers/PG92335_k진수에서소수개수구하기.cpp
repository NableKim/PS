#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<string> split(string str) {
    
    vector<string> v;
    int pre = 0;
    int idx = 0;
    bool flag = false;
    while (idx < str.length()) {
        if (str[idx] == '0') {
            if (!flag)  {
                string tmp = str.substr(pre, idx - pre);
                v.push_back(tmp);
                flag = true;
            }
        }
        else {
            if (flag == true) {
                flag = false;
                pre = idx;
            }
        }

        idx++;
    }

    if (!flag) {
        string tmp = str.substr(pre, idx - pre);
        v.push_back(tmp);
    }

    return v;
}

bool isPrime(long long n) {
    if (n == 1) return false;

    for (long long i = 2; i * i <= n; i++) {
        if (n % i == 0)
            return false;
    }
    return true;
}

int solution(int n, int k) {
    int answer = 0;

    // k�������� ǥ���ϱ�

    string str = "";
    while (n >= k) {
        int r = n % k;
        n = n / k;
        str = to_string(r) + str;
    }
    if (n != 0)
        str = to_string(n) + str;

    // 0�� �������� ������
    vector<string> v = split(str);
    
    // �� ���� �Ҽ����� ���� �� �Ҽ� ���� ����
    for (int i = 0; i < v.size(); i++) {
        if (isPrime(stoll(v[i])))
            answer++;
    }

    return answer;
}

int main() {
    cout << solution(21, 2);
}