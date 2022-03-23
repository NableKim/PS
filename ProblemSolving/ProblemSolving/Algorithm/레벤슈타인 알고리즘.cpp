#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int M[10][10];

int getStringDistance(string A, string B) {

	// 0행 초기화
	for (int i = 1; i <= B.length(); i++)
		M[0][i] = i;
	
	// 0열 초기화
	for (int i = 1; i <= A.length(); i++)
		M[i][0] = i;

	for (int y = 1; y <= A.length(); y++) {
		for (int x = 1; x <= B.length(); x++) {

			int cost = (A[y - 1] == B[x - 1]) ? 0 : 1;

			int addChar = M[y][x - 1] + 1;
			int minusChar = M[y-1][x] + 1;
			int replaceChar = M[y - 1][x - 1] + cost;

			M[y][x] = min(addChar, min(minusChar, replaceChar));
		}
	}

	return M[A.length()][B.length()];
}

int main() {

	string A = "horse";
	string B = "rose";

	cout << getStringDistance(A, B);

}