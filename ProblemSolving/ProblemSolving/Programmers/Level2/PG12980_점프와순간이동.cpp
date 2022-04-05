#include <iostream>
using namespace std;


int solution(int n)
{
    int ans = 0;

    while (n) {
        int r = n % 2;
        n /= 2;

        if (r == 1)
            ans++;
    }

    return ans;
}