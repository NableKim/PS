#include <iostream>
#include <string>
#include <vector>

#define MAP_SIZE 16

using namespace std;

int map1[MAP_SIZE][MAP_SIZE];
int map2[MAP_SIZE][MAP_SIZE];

string decode(int n, int len) {

    string tmp = "";

    while (n >= 2) {
        int r = n % 2;
        n /= 2;
        if (r == 0)
            tmp = " " + tmp;
        else
            tmp = "#" + tmp;
    }

    if (n == 0)
        tmp = " " + tmp;
    else
        tmp = "#" + tmp;

    while (tmp.size() < len)
        tmp = " " + tmp;

    return tmp;

}

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;

    for (int i = 0; i < n; i++) {
        
        string mapStr1 = decode(arr1[i], n);
        string mapStr2 = decode(arr2[i], n);

        string tmp = "";
        for (int j = 0; j < n; j++) {
            if (mapStr1[j] == '#' || mapStr2[j] == '#')
                tmp += "#";
            else
                tmp += " ";
        }
        answer.push_back(tmp);
    }

    return answer;
}

int main() {

    solution(5, { 9, 20, 28, 18, 11 }, { 30, 1, 21, 17, 28 });

    return 0;
}