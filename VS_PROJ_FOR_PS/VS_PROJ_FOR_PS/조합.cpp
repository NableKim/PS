#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct Edge {
	int s, e, d;
	Edge(int s, int e, int d) {
		this->s = s;
		this->e = e;
		this->d = d;
	}
};

int getParent(int *set, int s) {
	if (set[s] == s)
		return set[s];
	else
		return set[s] = getParent(set, set[s]);
}

void unionParent(int* set, int s, int e) {
	int sp = getParent(set, s);
	int ep = getParent(set, e);

	if (sp <= ep)
		set[ep] = sp;
	else
		set[sp] = ep;
}


bool isSameParent(int* set, int s, int e) {
	int sp = getParent(set, s);
	int ep = getParent(set, e);
	return sp == ep;
}

int main() {
	int n = 7;
	int m = 11;

	vector<Edge> v;
	v.push_back(Edge(1, 7, 12));
	v.push_back(Edge(1, 4, 23));
	v.push_back(Edge(1, 2, 26));
	v.push_back(Edge(2, 3, 36));
	v.push_back(Edge(2, 4, 21));
	v.push_back(Edge(2, 5, 45));
	v.push_back(Edge(3, 5, 29));
	v.push_back(Edge(3, 6, 37));
	v.push_back(Edge(3, 7, 55));
	v.push_back(Edge(4, 7, 20));
	v.push_back(Edge(5, 6, 30));

	sort(v.begin(), v.end());

	int set[8];
	for (int i = 1; i < 8; i++) {
		set[i] = i;	// 자기 정점의 부모는 자신
	}

	int cost = 0;
	for (int i = 0; i < v.size(); i++) {
		int s = v[i].s;
		int e = v[i].e;
		int d = v[i].d;

		if (!isSameParent(set, s, e)) {
			// 비용 증가
			cost += d;
			// 유니온
			unionParent(set, s, e);
		}
	}

	return 0;
}