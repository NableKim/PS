#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

string numberStr = "";
int answer;
unordered_map<int, bool> um;

void swap(int a, int b) {
    char tmp = numberStr[a];
    numberStr[a] = numberStr[b];
    numberStr[b] = tmp;
}

bool prime(int num) {
    if (num < 2) return false;

    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) return false;
    }
    return true;
}

void permutation(int depth, int len) {

    if (depth == len) {
        string numStr = numberStr.substr(0, len);
        int num = stoi(numStr);
        if (prime(num) && !um[num]) {
            um[num] = true;
            answer++;
        }

        return;
    }

    for (int i = depth; i < numberStr.length(); i++) {
        swap(i, depth);
        permutation(depth + 1, len);
        swap(i, depth);
    }

}

int solution(string numbers) {

    numberStr = numbers;

    for (int i = 1; i <= numbers.length(); i++) {
        permutation(0, i);
    }

    return answer;

}