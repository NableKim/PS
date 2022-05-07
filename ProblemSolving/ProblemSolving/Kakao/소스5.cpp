#include <iostream>
#include <string>
#include <vector>

using namespace std;

int Y, X;

vector<vector<int>> shiftRow(vector<vector<int>> rc) {
	vector<vector<int>> newRc;
	
	newRc.push_back(rc[Y - 1]);
	for (int y = 0; y < Y - 1; y++) {
		newRc.push_back(rc[y]);
	}
	return newRc;
}

vector<vector<int>> rotate(vector<vector<int>> rc) {
	vector<vector<int>> newRc;

	for (int y = 0; y < Y; y++) {
		newRc.push_back(rc[y]);
	}

	for (int x = 0; x <= X - 2; x++) {
		newRc[0][x + 1] = rc[0][x];
	}

	for (int y = 0; y <= Y - 2; y++) {
		newRc[y+1][X-1] = rc[y][X-1];
	}

	for (int x = X-1; x >= 1; x--) {
		newRc[Y-1][x-1] = rc[Y-1][x];
	}

	for (int y = Y-1; y >= 1; y--) {
		newRc[y-1][0] = rc[y][0];
	}

	return newRc;
}

vector<vector<int>> solution(vector<vector<int>> rc, vector<string> operations) {

	Y = rc.size();
	X = rc[0].size();

	for (string& op : operations) {

		if (op[0] == 'S') {
			rc = shiftRow(rc);
		}
		else {
			rc = rotate(rc);
		}

	}

	for (int y = 0; y < Y; y++) {
		for (int x = 0; x < X; x++) {
			cout << rc[y][x] << " ";
		}
		cout << endl;
	}

	return rc;
}

int main() {

	//vector<vector<int>> rc = { {1, 2, 3}, { 4, 5, 6 }, { 7, 8, 9 } };
	//vector<string> operations = { "Rotate", "ShiftRow" };
	vector<vector<int>> rc = { {1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12} };
	vector<string> operations = { "ShiftRow", "Rotate", "ShiftRow", "Rotate" };

	solution(rc, operations);
	/*vector<int> answers = solution();
	for (int i = 0; i < answers.size(); i++)
		cout << answers[i] << endl;*/

	return 0;
}


/*

for (int y = 0; y < Y; y++) {
		for (int x = 0; x < X; x++) {
			cout << rc[y][x] << " ";
		}
		cout << endl;
	}
*/