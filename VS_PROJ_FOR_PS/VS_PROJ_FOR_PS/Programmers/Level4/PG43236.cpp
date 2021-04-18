#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int solution(int distance, vector<int> rocks, int n) {
    int answer = 0;

    // 끝 지점
    rocks.push_back(distance);

    // 오름차순 정렬
    sort(rocks.begin(), rocks.end());

    // n개의 바위를 없애면서 바위 간 최소거리를 최대로 하는 값을 구하는 것임
    // -> n+1개 바위를 최초로 없애는 바위 간 거리를 구한 뒤, 그 거리의 값에 -1를 하면 정답
    int left = 1;
    int right = distance - 1;

    while (left < right) {
        int mid = (left + right) / 2;

        // 앞의 바위부터 바위간 거리를 구해서 mid값과 비교.
        // 작다면 제거한 바위 갯수 증가
        int lastIndex = -1; // 앞에 위치한 바위의 index
        int remove = 0; // 제거한 바위 갯수
        for (int i = 0; i < rocks.size(); i++) {

            int dis = rocks[i];
            if (lastIndex != -1)
                dis -= rocks[lastIndex];

            if (dis < mid)
                remove++;
            else
                lastIndex = i;
        }

        if (n < remove) {
            right = mid;
        }
        else
            left = mid + 1;
    }
    
    answer = right - 1;

    return answer;
}

int main() {

    int dis = 35;
    vector<int> rocks = { 2, 3, 7, 13, 22 };
    int n = 3;

    printf("%d", solution(dis, rocks, n));

	return 0;
}