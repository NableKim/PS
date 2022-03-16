#include <iostream>
#include <string>
#include <vector>

using namespace std;

long long solution(int a, int b, vector<int> g, vector<int> s, vector<int> w, vector<int> t) {
    long long left = 0;
    long long right = 1e15; // �ð� �ִ밪
    const long long DIV = 2;

    // �̺� Ž���� ���� ��� ã��
    while (left<=right) {
        long long mid = (left + right) / DIV;

        // mid�ð� ���� �� ���ð� ����� �� �ִ� �ѷ� ���ϱ�
        long long goldMax = 0;
        long long silverMax = 0;
        long long totalMax = 0;
        for (int i = 0; i < t.size(); i++) {
            long long tmp = t[i];
            long long repeatCnt = mid / (tmp * 2);
            if (mid % (tmp * 2) >= tmp) repeatCnt++;

            long long totalWeight = repeatCnt * (long long)w[i];
            totalMax += (totalWeight <= g[i]+s[i])? totalWeight: g[i]+s[i];
            goldMax += (totalWeight <= g[i])? totalWeight: g[i];
            silverMax += (totalWeight <= s[i])? totalWeight: s[i];
        }

        if ((long long)a + b <= totalMax
            && a <= goldMax
            && b <= silverMax) {
            right = mid - 1;
        }
        else
            left = mid + 1;
    }

    return right+1;
}

int main() {

    int a = 10;
    int b = 10;
    vector<int> g = { 100 };
    vector<int> s = { 100 };
    vector<int> w = { 7 };
    vector<int> t = { 10 };

    cout << solution(a, b, g,s,w,t);
    return 0;
}