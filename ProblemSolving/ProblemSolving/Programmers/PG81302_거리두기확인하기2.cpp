/*
* BFS�� Ȱ���Ͽ� ����ư �Ÿ� 2���Ͽ� ����� �ִ��� Ȯ���ϴ� ������� ����
* �ð����⵵ : O(N^2), N�� ������ ���� ���� �Ѻ��� ����
*/

#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

struct P {
    int y, x;
};

int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, -1, 0, 1 };

// �־��� ���� map�� ���ؼ� ����ư �Ÿ� 2���ϸ�ŭ bfs Ž��
bool bfs(int idx, int sy, int sx, vector<string> map) {
    
    queue<P> q;
    int check[5][5] = { 0, };
    check[sy][sx] = 1;
    q.push({ sy, sx });

    while (!q.empty()) {

        P front = q.front(); q.pop();

        for (int k = 0; k < 4; k++) {
            int ny = front.y + dy[k];
            int nx = front.x + dx[k];

            if (ny < 0 || ny >= 5 || nx < 0 || nx >= 5)
                continue;

            if(check[ny][nx])
                continue;

            if (map[ny][nx] == 'X')
                continue;

            // ����ư �Ÿ� 2������ Ȯ���ϱ�
            int nextDis = check[front.y][front.x] + 1;
            if (nextDis <= 3) {
                if (map[ny][nx] == 'P')
                    return false;

                check[ny][nx] = nextDis;
                q.push({ ny, nx });
            }
        }
    }
    
    return true;
}

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;

    // �� ���ǿ� ���Ͽ� �Ÿ��α� �Ǻ�
    for (int i = 0; i < places.size(); i++) {
        
        int flag = 1;   // ���� ������ ���� flag

        // �� ������ Map�� ������ bfs ����
        for (int y = 0; y < 5; y++) {
            for (int x = 0; x < 5; x++) {
                // ����� ��ġ�� ���� �밡������ ����ư �Ÿ� 2 �ݰ游ŭ bfs Ž��
                if (places[i][y][x] == 'P' 
                    && !bfs(i, y, x, places[i])) {
                    flag = 0;
                    break;
                }
            }

            if (flag == 0)
                break;
        }

        if (flag) answer.push_back(1);
        else answer.push_back(0);
    }

    return answer;
}

int main() {

    //vector<vector<string>> places = { {"POOOP", "OXXOX", "OPXPX", "OOXOX", "POXXP"}, {"POOPX", "OXPXP", "PXXXO", "OXXXO", "OOOPP"}, {"PXOPX", "OXOXP", "OXPOX", "OXXOP", "PXPOX"}, {"OOOXX", "XOOOX", "OOOXX", "OXOOX", "OOOOO"}, {"PXPXP", "XPXPX", "PXPXP", "XPXPX", "PXPXP"} };
    vector<vector<string>> places = { 
        {
            "PXPOO", 
            "XPXOO", 
            "OPOOO", 
            "OOOOO", 
            "OOOOO", 
        }, 
    };

    vector<int> answer = solution(places);

    for (int& a : answer)
        cout << a << " ";

    return 0;
}