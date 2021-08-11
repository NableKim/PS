// Time Complexity : O(N), N�� �� ������ ���� �ð�(<=360,000)
// Ư�� ����(��)�� �� ���� ��û�ϰ� �ִ��� CNT�ϴ� �κ��� ���� �ڵ忡�� ����
// ��û ������, ������ �켱������ �� ����صΰ�, ��û �ο����� ī�����ϴ� ��� ���

#include <iostream>
#include <vector>
#include <string>
#define MAX_SEC 360000
using namespace std;

int CNT[360000];    // 100�ð� == 360000 �̹Ƿ� �� ũ�⸸ŭ�� �迭�� ���� ī��������

int getSecFromStr(string strTime) {
    int hh, mm, ss;
    hh = stoi(strTime.substr(0, 2));
    mm = stoi(strTime.substr(3, 2));
    ss = stoi(strTime.substr(6, 2));
    return hh * 3600 + mm * 60 + ss;
}

string secToStr(int t) {

    int hh, mm, ss;
    string str = "";

    hh = t / 3600;
    t %= 3600;

    mm = t / 60;
    t %= 60;

    if (hh < 10) str += "0";
    str += to_string(hh);
    str += ":";

    if (mm < 10) str += "0";
    str += to_string(mm);
    str += ":";

    if (t < 10) str += "0";
    str += to_string(t);

    return str;
}

string solution(string play_time, string adv_time, vector<string> logs) {

    int play_sec, ad_sec;
    play_sec = getSecFromStr(play_time);
    ad_sec = getSecFromStr(adv_time);

    // �ð� ���ڿ����� �� ������ �ð����� ����
    int hh, mm, ss, start, end;
    for (string& s : logs) {
        start = getSecFromStr(s.substr(0, 8));
        end = getSecFromStr(s.substr(9));

        // ��û ������ ������, ������ �޸�
        CNT[start]++;
        CNT[end]--;
    }

    // Ư�� �ð�(��)�� ��, ��û �ο� ī��Ʈ
    for (int i = 1; i < play_sec; i++) {
        if (CNT[i] > 0)
            CNT[i] += CNT[i-1];
        else if (CNT[i] < 0)
            CNT[i] += CNT[i - 1];
        else
            CNT[i] = CNT[i - 1];
    }
    
    // adv_time ���̸�ŭ�� �迭 �������� ���
    long long sum = 0, max_sum = 0;
    for (int i = 0; i < ad_sec; i++)
        sum += CNT[i];
    max_sum = sum;

    // �ִ밪�� ������ ������ ã��
    int idx = 0, ansTime = 0;
    for (int i = ad_sec; i < play_sec; i++) {

        sum += CNT[i];      // ���ο� ���� ��������
        sum -= CNT[idx];    // �� ó�� ���� ����

        if (max_sum < sum) {
            max_sum = sum;
            ansTime = idx + 1;
        }

        idx++;
    }

    // �ִ밪�� ������ �������� �ð� ���ڿ��� ������ ���� ��ȯ
    string answer = secToStr(ansTime);

    return answer;
}

int main() {

    //cout << solution("50:00:00", "50:00:00", { "15:36:51-38:21:49", "10:14:18-15:36:51", "38:21:49-42:51:45" });
    cout << solution("02:03:55", "00:14:15", { "01:20:15-01:45:14", "00:40:31-01:00:00", "00:25:50-00:48:29", "01:30:59-01:53:29", "01:37:44-02:02:30" });

    return 0;
}