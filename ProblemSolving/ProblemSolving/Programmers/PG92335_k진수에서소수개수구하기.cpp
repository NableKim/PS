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

    // k진법으로 표현하기

    string str = "";
    while (n >= k) {
        int r = n % k;
        n = n / k;
        str = to_string(r) + str;
    }
    if (n != 0)
        str = to_string(n) + str;

    // 0을 기준으로 나누기
    vector<string> v = split(str);
    
    // 그 수가 소수인지 판정 후 소수 갯수 증가
    for (int i = 0; i < v.size(); i++) {
        if (isPrime(stoll(v[i])))
            answer++;
    }

    return answer;
}

int main() {
    cout << solution(21, 2);
}