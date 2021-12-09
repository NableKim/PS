// 시간복잡도 : O(N*logN)

/*
수도 코드

*** 한 사람의 총 이익금은 자신의 판매금과 입사자의 이익금으로 계산됨 ***

이 사람의 부모(추천자)는 누구다라는 정보를 저장
각 판매 정보를 갖고 아래 행위 반복
    어떤 사람이 얼마만큼 팔았으니
        부모에게 얼마 (>> 재귀적으로 전달(부모에게 줄 돈이 1원미만이면 안줌))
        자기꺼는 얼마
사람별 총 이익금을 정답 배열에 삽입 후 반환

*/
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

unordered_map<string, string> parent;   // 피추천자와 추천자 정보 저장
unordered_map<string, int> income;

void calculate(string seller, int amount) {

    if (amount <= 0)
        return;

    int present = amount * 0.1;
    calculate(parent[seller], present);
    income[seller] += (amount - present);
}

vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount) {
    vector<int> answer;

    for (int i = 0; i < enroll.size(); i++)  // N
        parent[enroll[i]] = referral[i];

    for (int i = 0; i < seller.size(); i++)  // N*logN
        calculate(seller[i], amount[i] * 100);

    for (int i = 0; i < enroll.size(); i++)  // N
        answer.push_back(income[enroll[i]]);

    return answer;
}