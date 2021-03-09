#include <iostream>
#include <vector>
using namespace std;

vector<int> n;
int sz, answer, tg;

void dfs(int index, int sum) {
    if (index == sz) {
        if (sum == tg)
            answer++;
        return;
    }

    dfs(index + 1, sum + n[index]);
    dfs(index + 1, sum - n[index]);
}

int solution(vector<int> numbers, int target) {
    n = numbers;
    sz = numbers.size();
    tg = target;
    dfs(0, 0);

    return answer;
}

int main() {
    cout << solution({ 1,1,1,1,1 }, 3);
    return 0;
}