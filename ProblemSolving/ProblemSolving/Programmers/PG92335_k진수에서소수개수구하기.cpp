#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool isPrime(long long n) {
    if (n < 2) return false;

    for (long long i = 2; i * i <= n; i++) {
        if (n % i == 0)
            return false;
    }
    return true;
}

int splitNCnt(string str) {
    
    str += '0'; // ���� 0 �ϳ� �߰�
    int answer = 0;
    long long value = str[0] - '0';
    for (int i = 1; i < str.size(); i++) {
        if (str[i] == '0') {
            isPrime(value) ? answer++: answer;
            value = 0;
        }
        else
            value = value * 10 + (str[i] - '0');
    }
    return answer;
}

int solution(int n, int k) {
    // k�������� ǥ���ϱ�
    string str = "";
    while (n) {
        str += ((n % k)+'0');
        n /= k;
    }
    reverse(str.begin(), str.end());

    // 0�� �������� ������ �Ҽ����� ����
    int answer = splitNCnt(str);
    return answer;
}

int main() {
    cout << solution(11011011, 10);
}