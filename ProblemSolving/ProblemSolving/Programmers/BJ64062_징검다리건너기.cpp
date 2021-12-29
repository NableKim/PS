#include <iostream>
#include <string>
#include <vector>
using namespace std;

int solution(vector<int> stones, int k) {
    int answer = 200000000;

    // 왼쪽에서 오른쪽 방향
    int cnt = 0;
    int pre = -1;
    for (int i = 0; i < stones.size(); i++) {
        if (stones[i] >= pre) {
            cnt++;
            if (cnt == k) {
                int minVal = stones[i];
                if(i>=k)
                    minVal = stones[i-k] > stones[i]? stones[i]: stones[i - k];
                answer = answer > minVal ? minVal : answer;
            }
                
        }
        else 
            cnt = 1;
        pre = stones[i];
    }

    for (int i = stones.size()-1; i >= 0; i--) {
        if (stones[i] >= pre) {
            cnt++;
            if (cnt == k) {
                int minVal = stones[i];
                if (i <= stones.size()-1-k)
                    minVal = stones[i + k] > stones[i] ? stones[i] : stones[i + k];
                answer = answer > minVal ? minVal : answer;
            }
        }
        else
            cnt = 1;
        pre = stones[i];
    }

    return answer;
}


int main() {

    vector<int> stones = { 6,1,2,5,4,10 };
    //vector<int> stones = { 2, 4, 5, 3, 2, 1, 4, 2, 5, 1 };
    //vector<int> stones = { 2, 2};
    int k = 4;

    cout << solution(stones, k);


	return 0;
}