#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string solution(vector<int> numbers);

struct A {
    int n1, n2;
};

bool cmp(A& a, A& b) {
    if (a.n1 == b.n1)
        return a.n2 < b.n2;
    return a.n1 > b.n1;
}

int main() {
    vector<int> numbers = { 0, 0, 0, 1 };
    cout << solution(numbers);
	return 0;
}

string solution(vector<int> numbers) {
    string answer = "";
    vector<A> v;
    
    int nSize = numbers.size();
    for (int i = 0; i < nSize; i++) {
        int n = numbers[i];
        if (n) {
            while (n < 1000)
                n = (n * 10) + (n % 10);
        }
        v.push_back({ n, numbers[i] });
    }

    sort(v.begin(), v.end(), cmp);

    if (v[0].n2 == 0)
        return "0";

    for (int i = 0; i < nSize; i++)
        answer += to_string(v[i].n2);   

    return answer;
}