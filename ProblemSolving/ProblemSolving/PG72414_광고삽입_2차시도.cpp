/*
* �ð����⵵ : O(N+K), N�� ������ ��û��� �����Ͱ���, K�� ��ü������ ��û�ð�(�ʴ���)
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

#define MAX_SECOND 360000

int C[MAX_SECOND];

string getSecToStr(int sec) {

    int hh = sec / 3600;
    sec %= 3600;
    
    int mm = sec / 60;
    int ss = sec % 60;

    string stime = "";
    stime = to_string(hh);
    if (hh < 10)
        stime = "0" + stime;

    stime += ":";
    if (mm < 10)
        stime += "0";
    stime += to_string(mm);
    
    stime += ":";
    if (ss < 10)
        stime += "0";
    stime += to_string(ss);

    return stime;
}

int getStrToSec(string stime) {
    
    int hh = stoi(stime.substr(0, 2));
    int mm = stoi(stime.substr(3, 2));
    int ss = stoi(stime.substr(6, 2));

    return  hh * 3600 + mm * 60 + ss;
}

string solution(string play_time, string adv_time, vector<string> logs) {
    string answer = "";

    // ��� ��û ��Ͽ� ���ؼ� �ʺ� ���� ��û�ڼ� ī��Ʈ 
    for (string& stime : logs) {                    // O(N*M). N�� ��û��� �����Ͱ���, M�� ��û��ϵ������� ���ڿ� ����(17)
        int hh = stoi(stime.substr(0, 2));          
        int mm = stoi(stime.substr(3, 2));
        int ss = stoi(stime.substr(6, 2));

        int start = hh * 3600 + mm * 60 + ss;
        
        hh = stoi(stime.substr(9, 2));
        mm = stoi(stime.substr(12, 2));
        ss = stoi(stime.substr(15, 2));

        int end = hh * 3600 + mm * 60 + ss;

        for (int i = start; i < end; i++)
            C[i]++;
    }

    int ad_start = 0;                   // ���� �����Ҷ� ���� ������ġ
    int ad_end = getStrToSec(adv_time); // ���� ���������� ���� ������ġ
    
    // ������ġ�� 0�ʷ� �Ҵ��� ���� ��û�ڼ� ���
    long long sum = 0;
    for (int i = ad_start; i < ad_end; i++) {       // O(K). K�� ���� ����ð�(�� ����) 
        sum += C[i];
    }
    
    // ���� ���� ��ġ�� �ڷ� ��ĭ�� �̷ﰡ�� �ִ� ���� ��û�ڼ� ���
    long long maxSum = sum; // �ִ� ���� ��û�ڼ�
    int answer_sec = 0;     // �ִ� ���� ��û�ڼ��� ����� ���� ���� ��ġ
    int limit = getStrToSec(play_time);
    for (int e = ad_end; e < limit; e++) {         // O(K). K�� ��ü ���� ����ð�(�� ����) 
        
        sum = sum - C[ad_start] + C[e];
        // ���� ����
        if (sum > maxSum) {
            maxSum = sum;
            answer_sec = ad_start + 1;
        }

        ad_start++;
    }

    return getSecToStr(answer_sec);
}

int main() {

    string play_time = "99:59:59";
    //string play_time = "02:03:55";
    string adv_time = "00:10:00";
    //string adv_time = "00:14:15";
    vector<string> logs = { "99:49:59-99:59:59", "99:49:59-99:59:59" };
    //vector<string> logs = { "01:20:15-01:45:14", "00:40:31-01:00:00", "00:25:50-00:48:29", "01:30:59-01:53:29", "01:37:44-02:02:30" };

    cout << solution(play_time, adv_time, logs);

    return 0;
}
