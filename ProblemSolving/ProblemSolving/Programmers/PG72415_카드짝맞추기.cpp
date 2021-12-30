#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct P {
    int y, x;
};

struct INFO {
    int y, x, c;
};

vector<P> cardPoint[7];
vector<int> cardOrder;
vector<P> subCardOrder;
int sy, sx;
int answer = 98765431;
vector<vector<int>> _board;

int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, -1, 0, 1 };

bool operator<(INFO a, INFO b) {
    return a.c > b.c;
}

int getMinDistance(int y, int x) {
    
    priority_queue<INFO> pq;
    pq.push({ sy, sx, 0 });

    while (!pq.empty()) {

        INFO front = pq.top();
        pq.pop();

        if (front.y == y && front.x == x)
            return front.c;

        // 네 방향에 대해서
        for (int k = 0; k < 4; k++) {
            int ny = front.y + dy[k];
            int nx = front.x + dx[k];

            if (ny < 0 || ny >= 4 || nx < 0 || nx >= 4)
                continue;

            pq.push({ ny, nx, front.c + 1 });
        }

        // ctrl키와 방향키 조합
        for (int k = 0; k < 4; k++) {
            // 해당 방향에 안뒤집은 카드가 있다면
            bool flag = false;
            int by = front.y;
            int bx = front.x;
            
            for (int r = 1; r <= 3; r++) {
                int ny = front.y + dy[k] * r;
                int nx = front.x + dx[k] * r;

                if (ny < 0 || ny >= 4 || nx < 0 || nx >= 4)
                    break;

                by = ny;
                bx = nx;

                if (_board[ny][nx] != 0) {
                    if(r!=1)
                        pq.push({ ny, nx, front.c + 1 });
                    flag = true;
                    break;
                }
            }

            // 해당 방향에 안뒤집은 카드가 없다면
            if (!flag) {
                if(front.y != by || front.x != bx)
                    pq.push({ by, bx, front.c + 1 });
            }
        }
    }
}


void simulation() {
    int sumDis = 0;

    // board 백업
    vector<vector<int>> _board_bk = _board;
    int by = sy;
    int bx = sx;

    for (int i = 0; i < subCardOrder.size(); i++) {
        // sy, sx에서 특정 좌표까지의 최소값
        int dis = getMinDistance(subCardOrder[i].y, subCardOrder[i].x);

        // 현재 좌표 재설정
        sy = subCardOrder[i].y;
        sx = subCardOrder[i].x;

        // 이동횟수 누적
        sumDis += dis;

        if (i % 2 == 1) {
            for (int k = 0; k < 2; k++) {
                int y = subCardOrder[i-k].y;
                int x = subCardOrder[i-k].x;
                _board[y][x] = 0;
            }
        }
    }
    
    // board를 복구
    _board = _board_bk;
    sy = by;
    sx = bx;

    if (sumDis < answer)
        answer = sumDis;
}

void setSubCardOrder(int depth, int N) {

    if (depth == N) {
        simulation();
        return;
    }

    for (int i = 0; i < 2; i++) {
        int cardNumber = cardOrder[depth];
        subCardOrder.push_back(cardPoint[cardNumber][i%2]);
        subCardOrder.push_back(cardPoint[cardNumber][(i+1)%2]);
        setSubCardOrder(depth + 1, N);
        subCardOrder.pop_back();
        subCardOrder.pop_back();
    }
}

void swap(int a, int b) {
    int tmp = cardOrder[a];
    cardOrder[a] = cardOrder[b];
    cardOrder[b] = tmp;
}

void setCardOrder(int depth, int N) {
    if (depth == N) {
        setSubCardOrder(0, N);
        return;
    }

    for (int i = depth; i < N; i++) {
        swap(i, depth);
        setCardOrder(depth + 1, N);
        swap(i, depth);
    }
}

int solution(vector<vector<int>> board, int r, int c) {

    _board = board;
    sy = r, sx = c;

    for (int y = 0; y < 4; y++) {
        for (int x = 0; x < 4; x++) {
            if (board[y][x] != 0)
                cardPoint[board[y][x]].push_back({ y, x });
        }
    }

    for (int i = 1; i <= 6; i++) {
        if (cardPoint[i].size() > 0)
            cardOrder.push_back(i);
    }
    
    setCardOrder(0, cardOrder.size());

    return answer+(cardOrder.size()*2);
}

int main() {
    
    //vector<vector<int>> board = { {1,0,0,3},{2,0,0,0},{0,0,0,2},{3,0,1,0} };
    //vector<vector<int>> board = { {1,0,0,3},{2,0,0,0},{0,0,0,2},{3,0,1,0} };
    vector<vector<int>> board = { {3,0,0,2},{0,0,1,0},{0,1,0,0},{2,0,0,3} };
    int r = 0;
    int c = 1;

    cout << solution(board, r, c);

    return 0;
}