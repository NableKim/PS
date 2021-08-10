#include <iostream>
#include <string>
using namespace std;

// Time Complexity : O(N), N is length of input string

/* when numRow is 5
 
0				8(==2*N-2)		16
1			7	9			15
2		6		10		14
3	5			11	13
4				12
*/

string convert(string s, int numRows) {
	
	if (numRows == 1)
		return s;

	string result = "";

	int interval = (numRows << 1) - 2;	// 2n-2
	
	// First Row
	for (int i = 0; i < s.length(); i += interval)
		result += s[i];

	// Middle Row
	for (int r = 1; r < numRows-1; r++) {

		int i1 = r;
		int i2 = interval - r;	// 2n-2-r

		while (1) {
			if (i1 >= s.length())
				break;
			result += s[i1];
			i1 += interval;

			if (i2 >= s.length())
				break;
			result += s[i2];
			i2 += interval;
		}
	}

	// Last Row
	for (int i = numRows-1; i < s.length(); i += interval)
		result += s[i];

	return result;
}

int main() {

	cout << convert("PAYPALISHIRING", 4);

}