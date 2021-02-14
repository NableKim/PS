#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

int cnt[21];	// 단품 index개로 구성한 조합이 최대 몇번 주문되었는가
unordered_map<string, int> um;	// "음식조합"이 주문된 횟수
vector<string> menu[11][21];	// menu[y][x] 단품 y개로 구성되어있으면서 x번 주문된 음식 조합들  
string order;	// 각 손님이 주문한 음식들

vector<string> solution(vector<string> orders, vector<int> course);

void combination(int depth, string str) {
	int sSize = str.size();
	if (sSize > 0) {
		um[str]++;	// 현재 음식 조합의 주문 횟수 증가
		cnt[sSize] = max(cnt[sSize], um[str]);	// sSize개짜리 음식의 최대 주문 횟수 업데이트
		menu[sSize][um[str]].push_back(str);
	}

	for (int i = depth; i < order.size(); i++)
	{
		str.push_back(order[i]);
		combination(i + 1, str);
		str.pop_back();
	}
}

int main() {
	vector<string> orders = { "XYZ", "XWY", "WXA" };
	vector<int> course = { 2,3,4 };

	vector<string> answer = solution(orders, course);

	for (string& s : answer)
		cout << s << endl;
	
	return 0;
}

vector<string> solution(vector<string> orders, vector<int> course) {
	vector<string> answer;

	// 손님의 주문 내역으로 만들 수 있는 조합 모두 구하기
	for (string& s : orders) {
		sort(s.begin(), s.end());
		order = s;
		combination(0, "");
	}

	// 정답을 찾아야함
	for (int& a : course) {
		if (cnt[a] > 1) {
			for(string& s: menu[a][cnt[a]])
				answer.push_back(s);
		}
	}
	
	sort(answer.begin(), answer.end());

	return answer;
}

