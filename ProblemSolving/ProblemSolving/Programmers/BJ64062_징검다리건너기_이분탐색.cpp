#include <iostream>
#include <vector>
using namespace std;

bool possible(int mid, int k, vector<int> stones) {

    int cnt = 0;
    for (int i = 0; i < stones.size(); i++) {
        if (stones[i] < mid) {
            cnt++;
            if (cnt >= k)
                return false;
        }
        else
            cnt = 0;
    }
    return true;
}

int solution(vector<int> stones, int k) {
    int answer = 0;

    int left = 1;
    int right = 200000000;
    
    while (left <= right) {
        int mid = (left + right) / 2;
        if (possible(mid, k, stones)) {
            answer = answer < mid ? mid : answer;
            left = mid + 1;
        }
        else
            right = mid - 1;
    }

    return answer;
}


int main() {

    //vector<int> stones = { 6,1,2,5,4,10 };
    vector<int> stones = { 2, 4, 5, 3, 2, 1, 4, 2, 5, 1 };
    //vector<int> stones = { 2, 2 };
    int k = 3;

    cout << solution(stones, k);


    return 0;
}