#include <string>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

int solution(vector<int> people, int limit);

int main() {
    vector<int> people = { 70, 60, 50, 40, 30};
    int limit = 100;

    int result = solution(people, limit);
    printf("%d\n", result);
    
    return 0;
}

int solution(vector<int> people, int limit) {
    int answer = 0;
    int pSize = people.size();

    sort(people.begin(), people.end(), greater<int>());

    int end = pSize - 1;
    for (int i = 0; i < pSize; i++) {
        if (people[i] * 2 <= limit) {
            answer += (end - i + 1) / 2;
            if ((end - i) % 2 == 1)
                answer += 1;
            break;
        }

        answer++;
        if (people[i] + people[end] <= limit)
            end--;
    }
    return answer;
}