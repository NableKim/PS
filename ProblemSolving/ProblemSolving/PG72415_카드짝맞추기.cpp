#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

struct CARD {
    int y, x, number;
};

struct P {
    int y, x, d;    // y, x, d(거리)
};

vector<CARD> card;
vector<int> pick;   // 순열을 구하기 위한 배열
vector<vector<int>> map;    // board 전역화
int sy, sx;         // 주어진 시작 위치
int minVal = 987654321;
int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, -1, 0, 1 };

bool operator<(P a, P b) {
    return a.d > b.d;
}

int bfs(int ty, int tx) {

    priority_queue<P> pq;
    pq.push({ sy, sx, 0 });

    while (!pq.empty()) {
        P front = pq.top();
        pq.pop();

        // 현재 위치가 목표 지점과 같다면
        if (front.y == ty && front.x == tx)
            return front.d;

        int ny, nx; // 다음 위치

        // 방향키로 한칸 이동하는 경우
        for (int k = 0; k < 4; k++) {
            ny = front.y + dy[k];
            nx = front.x + dx[k];

            if (ny < 0 || ny >= 4 || nx < 0 || nx >= 4) continue;
            
            pq.push({ ny, nx, front.d + 1 });
        }

        // ctrl+방향키를 누르는 경우
        for (int k = 0; k < 4; k++) {
            ny = front.y;
            nx = front.x;
            
            // 2~3칸까지 이동
            int interval = 2;
            for (; interval < 4; interval++) {
                int tmp_ny = front.y + dy[k] * interval;
                int tmp_nx = front.x + dx[k] * interval;

                // 범위를 벗어난다면
                if (tmp_ny < 0 || tmp_ny >= 4 || tmp_nx < 0 || tmp_nx >= 4) break;
                
                // 위치값 갱신
                ny = tmp_ny; nx = tmp_nx;

                if (map[tmp_ny][tmp_nx] != 0)
                    break;
            }

            if (ny != front.y || nx != front.x)
                pq.push({ ny, nx, front.d + 1 });
        }
    }

    return 9999;
}

void swap(int a, int b) {
    int tmp = pick[a];
    pick[a] = pick[b];
    pick[b] = tmp;
}

void permutation(int depth) {

    if (depth == card.size()) {
        
        // 같은 숫자인 카드를 연속으로 방문한 경우에 대한 순열만 필터링함
        for (int i = 0; i < card.size(); i+=2) {
            int firstCard = pick[i];
            int secondCard = pick[i + 1];
            if (card[firstCard].number != card[secondCard].number)
                return;
        }

        // 첫번째 카드부터 탐색 시작
        int sy_bk = sy, sx_bk = sx; // 시작 위치 백업
        int sum = 0;
        for (int i = 0; i < card.size(); i++) {
            sum += bfs(card[pick[i]].y, card[pick[i]].x);

            // 카드 짝을 맞췄다면 둘다 빈칸으로 만들기
            if (i % 2 == 1) {
                int index = pick[i];
                map[card[index].y][card[index].x] = 0;
                
                index = pick[i-1];
                map[card[index].y][card[index].x] = 0;
            }

            // 지금까지 구한 최소비용보다 길다면 더 볼 필요없음
            if (sum > minVal)
                break;

            sy = card[pick[i]].y;
            sx = card[pick[i]].x;
        }

        // 정답 갱신
        if (sum < minVal)
            minVal = sum;

        // 모든 카드들을 원위치 시킴
        for (int i = 0; i < pick.size(); i++) {
            int index = pick[i];
            map[card[index].y][card[index].x] = card[index].number;
        }
        sy = sy_bk; sx = sx_bk; // 기존 시작 위치 복구

        return;
    }

    for (int i = depth; i < pick.size(); i++) {
        swap(depth, i); // depth번째 원소에 i번째 원소가 들어감
        permutation(depth + 1);
        swap(depth, i); // 복구
    }
}


int solution(vector<vector<int>> board, int r, int c) {
    map = board;

    // Step 1. 시작점과 카드 번호별 위치를 저장해둠
    sy = r, sx = c;
    for (int y = 0; y < 4; y++) {
        for (int x = 0; x < 4; x++) {
            if (board[y][x] != 0) {
                card.push_back({ y, x, board[y][x] });
            }
        }
    }

    // Step 2. 카드 각각에 번호를 부여해서 같은 번호가 연속적으로 나오도록 순열을 구하기
    for (int i = 0; i < card.size(); i++)
        pick.push_back(i);

    permutation(0);

    // Step 3. 카드 순서에 따라 bfs 탐색을 수행

    // Step 4. bfs 탐색하면서 이동한 횟수 누적

    // Step 5. 정답 갱신


    return minVal+card.size();
}

int main() {
    
    //vector<vector<int>> board = { {1,0,0,3},{2,0,0,0},{0,0,0,2},{3,0,1,0} };
    vector<vector<int>> board = { {3, 0, 0, 2}, {0, 0, 1, 0}, {0, 1, 0, 0}, {2, 0, 0, 3} };
    int r = 1;
    int c = 0;

    cout << solution(board, r, c);

    return 0;
}