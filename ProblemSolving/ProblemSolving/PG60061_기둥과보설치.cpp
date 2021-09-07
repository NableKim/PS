/*
* �ð����⵵ : O(M+N^2), M�� build_frame ũ��, N�� �־��� ������ ����
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX_LEN 101

int PLATE[MAX_LEN][MAX_LEN];
int BAR[MAX_LEN][MAX_LEN];
int L;  // �� �� ���� ����

// N x N ũ���� �� ���� ��ǥ�ΰ�
bool range(int y, int x) {
    if (y<0 || y>L || x<0 || x>L)
        return false;
    return true;
}

// ����� ���� �� �ִ°�
bool canInstallBar(int y, int x) {

    // �� �� ���̶��
    if (y == L)
        return false;

    // �ٴ��̶��
    if (y == 0)
        return true;
    
    // ���� ���� ���� ����� �ǰ�
    if ((range(y, x-1) && PLATE[y][x - 1]) || PLATE[y][x])
        return true;

    // �ٸ� ��� ���� ����� �ǰ�
    if (range(y - 1, x) && BAR[y - 1][x])
        return true;

    return false;
}

// ���� ��ġ�� �� �ִ°�
bool canInstallBo(int y, int x) {

    // �ٴ��̰ų� ������ ���̶��
    if (y == 0 || x == L)
        return false;

    // �� �߿� �ϳ��� ����� �ִٸ�
    if ((range(y-1, x) && BAR[y-1][x]) || (range(y - 1, x+1) && BAR[y-1][x + 1]))
        return true;

    // �� �ʿ� ���� ��ġ�Ѵٸ�
    if ((range(y, x-1) && PLATE[y][x-1]) && (range(y, x+1) && PLATE[y][x+1]))
        return true;

    return false;
}

bool IsBoStable(int y, int x) {
    return canInstallBo(y, x);
}

bool IsBarStable(int y, int x) {
    return canInstallBar(y, x);
}

// ����� ������ �� �ִ°�
bool canDeleteBar(int y, int x) {

    // ���� ��� ���� ��������
    if (range(y + 1, x - 1) && PLATE[y + 1][x - 1]) {
        if (!IsBoStable(y + 1, x - 1))
            return false;
    }

    // ���� ��� ���� ��������
    if (range(y + 1, x) && PLATE[y + 1][x]) {
        if (!IsBoStable(y + 1, x))
            return false;
    }

    // ��� ����� ��������
    if (range(y + 1, x) && BAR[y + 1][x]) {
        if (!IsBarStable(y + 1, x))
            return false;
    }
    
    return true;
}

// ���� ������ �� �ִ°�
bool canDeleteBo(int y, int x) {

    // ���� ���� ��������
    if (range(y, x - 1) && PLATE[y][x - 1]) {
        if (!IsBoStable(y, x - 1))
            return false;
    }

    // ���� ���� ��������
    if (range(y, x+1) && PLATE[y][x+1]) {
        if (!IsBoStable(y, x+1))
            return false;
    }

    //// ���� �ϴ� ����� ��������
    //if (range(y-1, x) && BAR[y-1][x]) {
    //    if (!IsBarStable(y - 1, x))
    //        return false;
    //}

    //// ���� �ϴ� ����� ��������
    //if (range(y - 1, x + 1) && BAR[y - 1][x + 1]) {
    //    if (!IsBarStable(y - 1, x + 1))
    //        return false;
    //}

    // ���� ��� ����� ��������
    if (range(y, x) && BAR[y][x]) {
        if (!IsBarStable(y, x))
            return false;
    }

    // ���� ��� ����� ��������
    if (range(y, x+1) && BAR[y][x+1]) {
        if (!IsBarStable(y, x+1))
            return false;
    }

    return true;
}

vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
    vector<vector<int>> answer;

    L = n;

    int y, x, a, b;
    for (vector<int>& v : build_frame) {                      // O(M)
        x = v[0];
        y = v[1];
        a = v[2];
        b = v[3];

        if (a == 0) {   // ��� �̶��

            // y,x ��ġ�� ����� ���� �� �ִٸ�
            if(b==1 && canInstallBar(y, x))
                BAR[y][x] = 1;

            // y,x ��ġ�� ����� ������ �� �ִٸ�
            else if (b == 0) {
                BAR[y][x] = 0;  // y,x ��ġ�� ����� �켱 ����
                if (!canDeleteBar(y, x))
                    BAR[y][x] = 1;
            }

        }
        else {  // �� ���

            // y,x ��ġ�� ���� ���� �� �ִٸ�
            if (b == 1 && canInstallBo(y, x))
                PLATE[y][x] = 1;

            // y,x ��ġ�� ���� ������ �� �ִٸ�
            else if (b == 0) {
                PLATE[y][x] = 0;  // y,x ��ġ�� ���� �켱 ����
                if (!canDeleteBo(y, x))
                    PLATE[y][x] = 1;
            }
        }
    }

    for (int y = 0; y <= L; y++) {                  // O(N^2)
        for (int x = 0; x <= L; x++) {
            if (BAR[y][x] == 1)
                answer.push_back({ x, y, 0 });
        }
    }

    for (int y = 0; y <= L; y++) {                  // O(N^2)
        for (int x = 0; x <= L; x++) {
            if (PLATE[y][x] == 1)
                answer.push_back({ x, y, 1 });
        }
    }

    sort(answer.begin(), answer.end());

    return answer;
}

int main() {

    int n = 5;
    //vector<vector<int>> build_frame = { {1,0,0,1},{1,1,1,1},{2,1,0,1},{2,2,1,1},{5,0,0,1},{5,1,0,1},{4,2,1,1},{3,2,1,1} };
    //vector<vector<int>> build_frame = { {0,0,0,1},{2,0,0,1},{4,0,0,1},{0,1,1,1},{1,1,1,1},{2,1,1,1},{3,1,1,1},{2,0,0,0},{1,1,1,0},{2,2,0,1} };
    vector<vector<int>> build_frame = { 
        {0,0,0,1},
        {0,1,0,1},
        {0,2,0,1},
        
        {3,0,0,1},
        {3,1,0,1},
        {3,2,0,1},

        {0,3,1,1},
        {2,3,1,1},
        {1,3,1,1},
        
        

        {2,3,1,0},
    };

    vector<vector<int>> answer = solution(n, build_frame);

    cout << "hello";

    return 0;
}
