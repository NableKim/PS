#include <string>
#include <vector>
#include <iostream>

using namespace std;


int solution(vector<int> arr) {
    int i = 1;
    while (1) {
        bool flag = true;
        for (int& a : arr) {
            if (i % a != 0) {
                flag = false;
                break;
            }
        }
        if (flag)
            return i;
        i++;
    }
}


int main() {

    cout << solution({ 2,6,8,14 });

    return 0;
}