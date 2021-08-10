#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

typedef struct _RANGE {
    int start, end;
} RANGE;

vector<RANGE> v;

bool cmp(RANGE a, RANGE b) {
    return a.start < b.start;
}

int getOverlapTime(int s, int e, int ad_s, int ad_e) {

    // 광고 시간과 비교 시간이 아예 겹치지 않는 경우
    if (ad_e <= s || ad_s >= e)
        return 0;
    else if (s <= ad_s && ad_e <= e) {  // 광고 시간이 완전히 포함되는 경우
        return ad_e - ad_s;
    }
    else if (ad_s <= s && e <= ad_e) {  // 광고 시간이 완전히 덮는 경우
        return e - s;
    }
    else if (s < ad_s) {
        return e - ad_s;
    }
    else
        return ad_e - s;
}

string solution(string play_time, string adv_time, vector<string> logs) {
    string answer = "";

    int hh, mm, ss, hh2, mm2, ss2, adTime, pTime;
    hh = stoi(adv_time.substr(0, 2));
    mm = stoi(adv_time.substr(3, 2));
    ss = stoi(adv_time.substr(6, 2));
    adTime = hh * 3600 + mm * 60 + ss;

    hh = stoi(play_time.substr(0, 2));
    mm = stoi(play_time.substr(3, 2));
    ss = stoi(play_time.substr(6, 2));
    pTime = hh * 3600 + mm * 60 + ss;

    // logs에서 시간 문자열을 초 단위로 시작시간, 끝시간 값 획득
    for (string& s : logs) {

        hh = stoi(s.substr(0, 2));
        mm = stoi(s.substr(3, 2));
        ss = stoi(s.substr(6, 2));

        hh2 = stoi(s.substr(9, 2));
        mm2 = stoi(s.substr(12, 2));
        ss2 = stoi(s.substr(15, 2));

        int start, end;
        start = hh * 3600 + mm * 60 + ss;
        end = hh2 * 3600 + mm2 * 60 + ss2;

        v.push_back({ start, end });

    }

    // 맨처음 시작하는 경우 고려
    v.push_back({ 0, adTime });

    // 시작 순서를 기준으로 정렬
    sort(v.begin(), v.end(), cmp);

    long long maxVal = -1;
    int ansTime = 0;

    for (RANGE& r : v) {
        long long sum = 0;
        int start = r.start;        // 삽입된 광고의 시작 위치
        int end = r.start + adTime; // 삽입된 광고의 종료 위치
        
        if (end > pTime)
            end = pTime;

        // 동영상 시청 기록으로부터 겹치는 구간값 가져오기
        for (int i = 1; i < v.size(); i++) {
            // 가지치기
            if (end < v[i].start)
                break;

            sum += (long long) getOverlapTime(v[i].start, v[i].end, start, end);
        }

        if (maxVal < sum) {
            maxVal = sum;
            ansTime = r.start;
        }
    }

    hh = ansTime / 3600;
    ansTime %= 3600;
    mm = ansTime / 60;
    ansTime %= 60;


    if (hh < 10)
        answer = "0" + to_string(hh);
    else
        answer = to_string(hh);
    answer += ":";

    if (mm < 10)
        answer += "0" + to_string(mm);
    else
        answer += to_string(mm);
    answer += ":";

    if (ansTime < 10)
        answer += "0" + to_string(ansTime);
    else
        answer += to_string(ansTime);

    return answer;
}

int main() {

    cout << solution("50:00:00", "50:00:00", { "15:36:51-38:21:49", "10:14:18-15:36:51", "38:21:49-42:51:45" });

    return 0;
}