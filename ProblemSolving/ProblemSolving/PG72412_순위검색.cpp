/*
*   ## ���̵��
*    1. info ���ڿ����� �־��� �����͵��� �Ľ�
*    2. ������ ������ ���� �迭�� ����
*    3. ������ �������� ����
*    4. query���� �а�
*    5. query �������� ������ �������� ������ �̾Ƴ���
*    6. ���ϴ� ���� �̻��� ���� �ε����� ã�� �ű⼭���� Ž�� ����
* ��Ȯ�� ������ 100���̳� ȿ�������� �ð� �ʰ�
* �ð����⵵ : O(N*M). N�� Info ����, M�� query ����
*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct S {
    string lang, pos, level, food;
    int score;
};

vector<S> db;

vector<string> parsing(string str) {
    vector<string> tmp;
    int index = -1;
    for (int i = 0; i < str.size(); i++) {
        if (str[i] == ' ') {
            index++;
            string s_tmp = str.substr(index, i - index);
            tmp.push_back(s_tmp);
            index = i;
        }
    }
    index++;
    tmp.push_back(str.substr(index));
    return tmp;
}

bool cmp(S a, S b) {
    return a.score < b.score;
}

int getLowerBound(int left, int right, int target) {

    while (left < right) {
        int mid = (left + right) >> 1;
        
        if (db[mid].score < target)
            left = mid + 1;
        else
            right = mid;
    }

    return right;
}

vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> answer;

    for (string& str : info) {
        vector<string> tmp = parsing(str);

        db.push_back({ 
            tmp[0], 
            tmp[1] , 
            tmp[2], 
            tmp[3], 
            stoi(tmp[4])
        });
    }

    sort(db.begin(), db.end(), cmp);

    for (string& str : query) { // O(M)
        vector<string> tmp = parsing(str);

        // tmp[7] score�� �̻��� ������ ���ʷ� �߰ߵǴ� �κ� ã��
        int index = getLowerBound(0, db.size(), stoi(tmp[7]));  // O(logN)

        int cnt = 0;
        for (int i = index; i < db.size(); i++) {   // O(N)
            
            // ��� ��
            if (tmp[0][0] != '-' && db[i].lang[0] != tmp[0][0])
                continue;

            // ���� ��
            if (tmp[2][0] != '-' && db[i].pos[0] != tmp[2][0])
                continue;

            // ��� ��
            if (tmp[4][0] != '-' && db[i].level[0] != tmp[4][0])
                continue;

            // ���� ��
            if (tmp[6][0] != '-' && db[i].food[0] != tmp[6][0])
                continue;

            cnt++;
        }

        answer.push_back(cnt);
    }


    return answer;
}

int main() {

    vector<string> info = {"java backend junior pizza 150", "python frontend senior chicken 210", "python frontend senior chicken 150", "cpp backend senior pizza 260", "java backend junior chicken 80", "python backend senior chicken 50"};
    vector<string> qeury = { "java and backend and junior and pizza 100","python and frontend and senior and chicken 200","cpp and - and senior and pizza 250","- and backend and senior and - 150","- and - and - and chicken 100","- and - and - and - 150" };

    vector<int> answer = solution(info, qeury);

    for (int a : answer)
        cout << a << " ";
    cout << endl;
    

    return 0;
}