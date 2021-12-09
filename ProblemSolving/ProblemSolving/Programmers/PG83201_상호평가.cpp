// �ð����⵵ : O(N^2), N�� �л� ��

#include <iostream>
#include <string>
#include <vector>
using namespace std;

string getGrade(int sum) {
    if (sum >= 90)
        return "A";
    else if (sum >= 80)
        return "B";
    else if (sum >= 70)
        return "C";
    else if (sum >= 50)
        return "D";
    else
        return "F";
}

string solution(vector<vector<int>> scores) {
    string answer = "";
    
    // �� �л��� ���� �� ������ �޸�
    // �� �л��� �ְ���, ������ ���� ���ϱ�
    // �� �л��� ���� �� ������ �����Ѱ� ����� ī����
    // �ְ�, ���������� ������ ���԰� �װ� ���� �� ������ �����ϴ°Ŷ�� ��տ��� ����

    int N = scores.size();
    for (int x = 0; x < N; x++) {

        int self = scores[x][x];    // ���� �� ����
        int cnt = 0;                // ���� �� ������ ������ ����
        int max = -1;               // �ְ���
        int min = 1000;             // ������
        int sum = 0;                // �� ���� �� �հ�

        for (int y = 0; y < N; y++) {
            // ���� �� ������ ������ ���� ����
            if (scores[y][x] == self)
                cnt++;

            // �ִ밪 ���
            if (max < scores[y][x])
                max = scores[y][x];

            // �ּҰ� ���
            if (min > scores[y][x])
                min = scores[y][x];
        
            sum += scores[y][x];
        }

        if ((max == self || min == self) && cnt == 1) {
            sum -= self;
            sum /= N-1;
        }
        else
            sum /= N;

        answer += getGrade(sum);
    }
    
    return answer;
}

int main() {

    cout << solution({ {50,90},{50,87} });


    return 0;
}