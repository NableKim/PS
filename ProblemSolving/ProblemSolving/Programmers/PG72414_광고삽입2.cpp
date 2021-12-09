// Time Complexity : O(N), N은 초 단위의 광고 시간(<=360,000)
// 특정 시점(초)에 몇 명이 시청하고 있는지 CNT하는 부분을 기존 코드에서 개선
// 시청 시작점, 끝점만 우선적으로 다 기록해두고, 시청 인원수을 카운팅하는 방식 사용

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
    str += to_string(t);

    return str;
}

string solution(string play_time, string adv_time, vector<string> logs) {

    int play_sec, ad_sec;
    play_sec = getSecFromStr(play_time);
    ad_sec = getSecFromStr(adv_time);

    // 시간 문자열에서 초 단위의 시간값을 저장
    int hh, mm, ss, start, end;
    for (string& s : logs) {
        start = getSecFromStr(s.substr(0, 8));
        end = getSecFromStr(s.substr(9));

        // 시청 구간의 시작점, 종료점 메모
        CNT[start]++;
        CNT[end]--;
    }

    // 특정 시간(초)일 때, 시청 인원 카운트
    for (int i = 1; i < play_sec; i++) {
        if (CNT[i] > 0)
            CNT[i] += CNT[i-1];
        else if (CNT[i] < 0)
            CNT[i] += CNT[i - 1];
        else
            CNT[i] = CNT[i - 1];
    }
    
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
    cout << solution("02:03:55", "00:14:15", { "01:20:15-01:45:14", "00:40:31-01:00:00", "00:25:50-00:48:29", "01:30:59-01:53:29", "01:37:44-02:02:30" });

    return 0;
}