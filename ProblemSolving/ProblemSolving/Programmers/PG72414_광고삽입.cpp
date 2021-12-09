// Time Complexity : O(N*M), N은 logs 수. M은 초 단위의 광고 시간

#include <iostream>
#include <vector>
#include <string>
#define MAX_SEC 360000
using namespace std;

int CNT[360000];    // 100시간 == 360000 이므로 이 크기만큼의 배열을 만들어서 카운팅하자

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
    str +=  to_string(t);

    return str;
}

string solution(string play_time, string adv_time, vector<string> logs) {
    
    // 시간 문자열에서 초 단위의 시간값을 저장
    int hh, mm, ss, start, end;
    for (string& s : logs) {
        start = getSecFromStr(s.substr(0, 8));
        end = getSecFromStr(s.substr(9));

        for (int i = start; i < end; i++) CNT[i]++; // 해당 초에 대한 시청 인원 카운트
    }

    int play_sec, ad_sec;
    play_sec = getSecFromStr(play_time);
    ad_sec = getSecFromStr(adv_time);  
    
    // adv_time 길이만큼의 배열 누적합을 계산
    long long sum = 0, max_sum = 0;
    for (int i = 0; i < ad_sec; i++)
        sum += CNT[i];
    max_sum = sum;

    // 최대값을 가지는 구간을 찾기
    int idx = 0, ansTime = 0;
    for (int i = ad_sec; i < play_sec; i++) {
        
        sum += CNT[i];      // 새로운 값을 마지막에
        sum -= CNT[idx];    // 맨 처음 값은 제거

        if (max_sum < sum) {
            max_sum = sum;
            ansTime = idx + 1;
        }

        idx++;
    }
        
    // 최대값을 가지는 시작점을 시간 문자열로 변경후 정답 반환
    string answer = secToStr(ansTime);

    return answer;
}

int main() {

    //cout << solution("50:00:00", "50:00:00", { "15:36:51-38:21:49", "10:14:18-15:36:51", "38:21:49-42:51:45" });
    cout << solution("02:03:55", "00:14:15"	,{"01:20:15-01:45:14", "00:40:31-01:00:00", "00:25:50-00:48:29", "01:30:59-01:53:29", "01:37:44-02:02:30"});

    return 0;
}