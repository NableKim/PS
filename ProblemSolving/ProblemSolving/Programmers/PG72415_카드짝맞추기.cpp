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
    int y, x, d;    // y, x, d(�Ÿ�)
};

vector<CARD> card;
vector<int> pick;   // ������ ���ϱ� ���� �迭
vector<vector<int>> map;    // board ����ȭ
int sy, sx;         // �־��� ���� ��ġ
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

        // ���� ��ġ�� ��ǥ ������ ���ٸ�
        if (front.y == ty && front.x == tx)
            return front.d;

        int ny, nx; // ���� ��ġ

        // ����Ű�� ��ĭ �̵��ϴ� ���
        for (int k = 0; k < 4; k++) {
            ny = front.y + dy[k];
            nx = front.x + dx[k];

            if (ny < 0 || ny >= 4 || nx < 0 || nx >= 4) continue;
            
            pq.push({ ny, nx, front.d + 1 });
        }

        // ctrl+����Ű�� ������ ���
        for (int k = 0; k < 4; k++) {
            ny = front.y;
            nx = front.x;
            
            // 2~3ĭ���� �̵�
            int interval = 2;
            for (; interval < 4; interval++) {
                int tmp_ny = front.y + dy[k] * interval;
                int tmp_nx = front.x + dx[k] * interval;

                // ������ ����ٸ�
                if (tmp_ny < 0 || tmp_ny >= 4 || tmp_nx < 0 || tmp_nx >= 4) break;
                
                // ��ġ�� ����
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
        
        // ���� ������ ī�带 �������� �湮�� ��쿡 ���� ������ ���͸���
        for (int i = 0; i < card.size(); i+=2) {
            int firstCard = pick[i];
            int secondCard = pick[i + 1];
            if (card[firstCard].number != card[secondCard].number)
                return;
        }

        // ù��° ī����� Ž�� ����
        int sy_bk = sy, sx_bk = sx; // ���� ��ġ ���
        int sum = 0;
        for (int i = 0; i < card.size(); i++) {
            sum += bfs(card[pick[i]].y, card[pick[i]].x);

            // ī�� ¦�� ����ٸ� �Ѵ� ��ĭ���� �����
            if (i % 2 == 1) {
                int index = pick[i];
                map[card[index].y][card[index].x] = 0;
                
                index = pick[i-1];
                map[card[index].y][card[index].x] = 0;
            }

            // ���ݱ��� ���� �ּҺ�뺸�� ��ٸ� �� �� �ʿ����
            if (sum > minVal)
                break;

            sy = card[pick[i]].y;
            sx = card[pick[i]].x;
        }

        // ���� ����
        if (sum < minVal)
            minVal = sum;

        // ��� ī����� ����ġ ��Ŵ
        for (int i = 0; i < pick.size(); i++) {
            int index = pick[i];
            map[card[index].y][card[index].x] = card[index].number;
        }
        sy = sy_bk; sx = sx_bk; // ���� ���� ��ġ ����

        return;
    }

    for (int i = depth; i < pick.size(); i++) {
        swap(depth, i); // depth��° ���ҿ� i��° ���Ұ� ��
        permutation(depth + 1);
        swap(depth, i); // ����
    }
}


int solution(vector<vector<int>> board, int r, int c) {
    map = board;

    // Step 1. �������� ī�� ��ȣ�� ��ġ�� �����ص�
    sy = r, sx = c;
    for (int y = 0; y < 4; y++) {
        for (int x = 0; x < 4; x++) {
            if (board[y][x] != 0) {
                card.push_back({ y, x, board[y][x] });
            }
        }
    }

    // Step 2. ī�� ������ ��ȣ�� �ο��ؼ� ���� ��ȣ�� ���������� �������� ������ ���ϱ�
    for (int i = 0; i < card.size(); i++)
        pick.push_back(i);

    permutation(0);

    // Step 3. ī�� ������ ���� bfs Ž���� ����

    // Step 4. bfs Ž���ϸ鼭 �̵��� Ƚ�� ����

    // Step 5. ���� ����


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