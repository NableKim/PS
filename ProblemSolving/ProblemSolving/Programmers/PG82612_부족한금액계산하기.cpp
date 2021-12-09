#include <cstdio>
using namespace std;

long long solution(int price, int money, int count)
{
    long long sum = (long long) ((count * (count + 1)) >> 1) * price;
    return sum > money? sum-money: 0;
}

int main() {

    printf("%lld", solution(3, 20, 4));

	return 0;
}