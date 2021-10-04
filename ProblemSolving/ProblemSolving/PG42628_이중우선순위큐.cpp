// 시간복잡도 : O(N*logN). N은 operations 개수

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <functional>
using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer = { 0, 0 };

    // 최대힙과 최소힙
    priority_queue<int, vector<int>, less<int>> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;
    
    // 현존하는 최대힙, 최소힙에서 몇개를 더 빼야하는가
    int left=0, right = 0;

    for (string& s : operations) {                      // O(N)
        if (s[0] == 'I') {
            // 최대힙이 비어있는 경우라면, 완전히 비우고 담기
            if (maxHeap.size() - left == 0) {
                while (!maxHeap.empty())
                    maxHeap.pop();
                left = 0;
            }
            maxHeap.push(stoi(s.substr(2)));            // O(logN)

            // 최소힙이 비어있는 경우라면, 완전히 비우고 담기
            if (minHeap.size() - right == 0) {
                while (!minHeap.empty())
                    minHeap.pop();
                right = 0;
            }
            minHeap.push(stoi(s.substr(2)));
        }
        else if (s[2] == '-') {
            // 최소값 삭제
            if (minHeap.size() - right > 0) {
                minHeap.pop();                          // O(logN)
                left++;
            }
        }
        else {
            // 최대값 삭제
            if (maxHeap.size() - left > 0) {
                maxHeap.pop();                          // O(logN)
                right++;
            }
        }
    }

    if (minHeap.size() - right > 0 && maxHeap.size() - left > 0) {
        answer.clear();
        answer.push_back(maxHeap.top());
        answer.push_back(minHeap.top());
    }

    return answer;
}

int main() {

    //vector<string> operations = { "I 16", "I -5643", "D -1", "D 1", "D 1", "I 123", "D -1" };
    vector<string> operations = { "I -45", "I 653", "D 1", "I -642", "I 45", "I 97", "D 1", "D -1", "I 333" };

    vector<int> answer = solution(operations);
    for (int& a : answer)
        cout << a << " ";

    return 0;
}