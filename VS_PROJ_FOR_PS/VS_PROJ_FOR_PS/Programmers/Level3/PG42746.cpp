#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(string& s1, string& s2) {
    if (s1 + s2 > s2 + s1)
        return true;
    return false;
}

string solution(vector<int> numbers) {
    string answer = "";

    vector<string> v;
    
    for (int& n : numbers)
        v.push_back(to_string(n));

    sort(v.begin(), v.end(), cmp);

    if (v[0]=="0")
        return "0";

    return answer;
}

int main() {
    vector<int> numbers = { 334, 33 };
    cout << solution(numbers);
	return 0;
}


