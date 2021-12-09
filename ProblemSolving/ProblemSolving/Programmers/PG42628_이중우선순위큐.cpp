// �ð����⵵ : O(N*logN). N�� operations ����

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <functional>
using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer = { 0, 0 };

    // �ִ����� �ּ���
    priority_queue<int, vector<int>, less<int>> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;
    
    // �����ϴ� �ִ���, �ּ������� ��� �� �����ϴ°�
    int left=0, right = 0;

    for (string& s : operations) {                      // O(N)
        if (s[0] == 'I') {
            // �ִ����� ����ִ� �����, ������ ���� ���
            if (maxHeap.size() - left == 0) {
                while (!maxHeap.empty())
                    maxHeap.pop();
                left = 0;
            }
            maxHeap.push(stoi(s.substr(2)));            // O(logN)

            // �ּ����� ����ִ� �����, ������ ���� ���
            if (minHeap.size() - right == 0) {
                while (!minHeap.empty())
                    minHeap.pop();
                right = 0;
            }
            minHeap.push(stoi(s.substr(2)));
        }
        else if (s[2] == '-') {
            // �ּҰ� ����
            if (minHeap.size() - right > 0) {
                minHeap.pop();                          // O(logN)
                left++;
            }
        }
        else {
            // �ִ밪 ����
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