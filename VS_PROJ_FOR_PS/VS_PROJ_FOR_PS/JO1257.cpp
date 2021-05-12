#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

struct LINE {
	int s, e, n;	// 시작 번호, 끝 번호, 몇번째 전기줄
};

bool alive[100001];

bool cmp(LINE& a, LINE& b) {
	if (a.s == b.s) {
		return a.e < b.e;
	}
	return a.s < b.s;
}

// target 값보다 최초로 커지는 지점(index)를 찾기
int binary_search(int end, vector<LINE>& lis, int target) {

	int left = 0;
	int right = end;

	while (left < right) {
		int mid = (left + right) / 2;

		if (lis[mid].e <= target)
			left = mid + 1;
		else
			right = mid;
	}
	return right;
}

int main() {
	int N;
	vector<LINE> v;

	//freopen("Text.txt", "r", stdin);

	scanf(" %d", &N);
	for (int i = 0, s, e; i < N; i++) {
		scanf(" %d %d", &s, &e);
		v.push_back({ s, e, i });
	}
	
	// A 전봇대에서 뻗어나가는 시작번호를 기준으로 오름 차순 정렬
	sort(v.begin(), v.end(), cmp);

	// LIS 수열을 구해야하는 상황
	vector<LINE> lis;
	vector<int> lis_index;	// LIS를 이루는 수열을 구하기 위한 배열
	lis.push_back(v[0]);	// lis 배열에 첫번째 전기줄 정보 넣기
	lis_index.push_back(0);
	int tail_idx = 0;	// lis 배열의 맨 마지막 인덱스
	for (int i = 1; i < N; i++) {
		if (lis[tail_idx].e <= v[i].e) {
			lis.push_back(v[i]);
			tail_idx++;
		}
		else {
			int idx = binary_search(tail_idx, lis, v[i].e);
			lis[idx] = v[i];
		}
		lis_index.push_back(tail_idx);
	}

	// 몇개 잘라야하나 출력
	printf("%d\n", N - tail_idx - 1);

	// lis 배열 얻기
	vector<int> conn;	// 남겨야하는 전기줄 번호
	int end = lis_index.size() - 1;
	for (int i = tail_idx; i >= 0; i--) {
		for (int j = end; j >= 0; j--) {
			if (lis_index[j] == i) {
				conn.push_back(v[j].n);
				end = j-1;
				break;
			}
		}
	}
	sort(conn.begin(), conn.end());

	
	for (int i = 0; i < conn.size(); i++)
		alive[v[conn[i]].n] = true;

	// 잘라야하는 전기줄 번호 출력
	for (int i = 0; i < N; i++) {
		if (!alive[i]) printf("%d\n", i+1);
	}

	return 0;
}

//int main() {
//	vector<LINE> lis = { 
//		{1, 1, 1}, 
//		{1, 2, 1}, 
//		{1, 3, 1}, 
//		{1, 3, 1}, 
//		{1, 3, 1}, 
//		{1, 5, 1}, 
//	};
//
//	printf("%d", binary_search(6, lis, 5));
//	return 0;
//}