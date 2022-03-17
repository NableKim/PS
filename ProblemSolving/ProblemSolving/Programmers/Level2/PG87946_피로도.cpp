#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int> arr;
int maxVal;

void swap(int a, int b) {
    int tmp = arr[a];
    arr[a] = arr[b];
    arr[b] = tmp;
}

void nPr(int depth, int n, vector<vector<int>>& dungeons, int k) {
    if (depth == n) {
        
        int cnt = 0;
        int energy = k;
        for (int i = 0; i < n; i++) {
            int index = arr[i];
            if (energy < dungeons[index][0]) break;
            energy -= dungeons[index][1];
            cnt++;
        }
        
        if (maxVal < cnt)
            maxVal = cnt;

        return;
    }

    for (int i = depth; i < n; i++) {
        swap(depth, i);
        nPr(depth + 1, n, dungeons, k);
        swap(depth, i);
    }
}

int solution(int k, vector<vector<int>> dungeons) {

    for (int i = 0; i < dungeons.size(); i++)
        arr.push_back(i);

    nPr(0, dungeons.size(), dungeons, k);

    return maxVal;
}

int main() {

    int k = 80;
    vector<vector<int>> dungeons = { {80,20},{50,40},{30,10} };
    cout << solution(k, dungeons);

    return 0;
}