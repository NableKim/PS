#include <iostream>
#include <string>
#include <vector>
using namespace std;

#define MAX_NUM 10000

int M[MAX_NUM]; // 입차 시간 기록
int F[MAX_NUM];
int basicMinutes, basicFee, scale, price;

int getTimeStrToMinutes(string tStr) {
    string hh = tStr.substr(0, 2);
    string mm = tStr.substr(3);
    return (stoi(hh)*60)+stoi(mm);
}

int getPrice(int number, int t) {
    int sum = basicFee;
    if (t > basicMinutes) {
        int o = (t - basicMinutes) / scale;
        int rr = (t - basicMinutes) % scale;
        if (rr != 0)
            o++;
        sum += (price * o);
    }
    return sum;
}

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;

    basicMinutes = fees[0];
    basicFee = fees[1];
    scale = fees[2];
    price = fees[3];

    for (int i = 0; i < MAX_NUM; i++)
        M[i] = -1;

    for (string& r : records) {
        string tStr = r.substr(0, 5);
        string nStr = r.substr(6, 5);
        string oStr = r.substr(11);

        int t = getTimeStrToMinutes(tStr);
        int number = stoi(nStr);

        if (oStr[0] == 'I')
            M[number] = t;
        else {
            F[number] += (t - M[number]);
            M[number] = -1;
        }
    }

    for (int i = 0; i < MAX_NUM; i++) {
        if (M[i] != -1) {
            F[i] += 1439 - M[i]; 
            M[i] = -1;
        }
        if (F[i]) {
            int sum = getPrice(i, F[i]);
            answer.push_back(sum);
        }
    }

    return answer;
}

int main() {


    vector<int> fees = { 180, 5000, 10, 600 };
    vector<string> records = { "05:34 5961 IN", "06:00 0000 IN", "06:34 0000 OUT", "07:59 5961 OUT", "07:59 0148 IN", "18:59 0000 IN", "19:09 0148 OUT", "22:59 5961 IN", "23:00 5961 OUT" };
    vector<int> answer = solution(fees, records);

    for (int a : answer)
        cout << a << endl;
    
    return 0;
}