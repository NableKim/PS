// �ð����⵵ : O(N^2)

#include <string>
#include <vector>
#include <algorithm>
using namespace std;

long long F[21];

vector<int> solution(int n, long long k) {

    vector<int> answer;


    // ���丮�� ���
    F[0] = 1;
    for (int i = 1; i < 21; i++)
        F[i] = i * F[i - 1];

    // v[] = {1, 2, 3, 4, ..., n} �ʱ�ȭ 
    vector<int> v;
    for (int i = 1; i <= n; i++)
        v.push_back(i);

    int flag = 0;
    for (int i = n; i > 0; i--) {
        long long q = k / F[i - 1];
        long long r = k % F[i - 1];

        // �������� 0�� ���
        if (r == 0) {
            q -= 1;
            flag = 1;
        }
        // �������� 1�� ���
        else if (r == 1)
            flag = 2;

        // �� ó�� ���� i��° �ڸ��� �� �� ���ϱ�
        answer.push_back(v[q]);

        // ���� �ڸ� ���� ������ ����
        vector<int> tmp;
        for (int j = 0; j < v.size(); j++) {
            if (v[j] == v[q]) continue;
            tmp.push_back(v[j]);
        }

        v.clear();
        v = tmp;
        k = r;

        // �� �ڸ��� � ���ڰ� ���� �� �������ٸ�
        if (flag)
            break;
    }

    if (flag == 1) {
        for (int i = v.size() - 1; i >= 0; i--)
            answer.push_back(v[i]);
    }
    else {
        for (int i = 0; i < v.size(); i++)
            answer.push_back(v[i]);
    }


    return answer;
}