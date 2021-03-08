#include <iostream>
#include <cstring>
using namespace std;

#define DIV 1234567

int memo[100001];

int solution(int n) {
    if (n == 0)
        return 0;
    else if (n == 1)
        return 1;
    else if (memo[n] != 0)
        return memo[n];
    else
        return memo[n]=((solution(n - 1)% DIV) + (solution(n - 2)% DIV))%DIV;
}

int main() {

    memset(memo, -1, sizeof(memo));
    cout << solution(5);

    return 0;
}
