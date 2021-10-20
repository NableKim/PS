// �ð����⵵ : O(N*logN)

/*
���� �ڵ�

*** �� ����� �� ���ͱ��� �ڽ��� �Ǹűݰ� �Ի����� ���ͱ����� ���� ***

�� ����� �θ�(��õ��)�� �����ٶ�� ������ ����
�� �Ǹ� ������ ���� �Ʒ� ���� �ݺ�
    � ����� �󸶸�ŭ �Ⱦ�����
        �θ𿡰� �� (>> ��������� ����(�θ𿡰� �� ���� 1���̸��̸� ����))
        �ڱⲨ�� ��
����� �� ���ͱ��� ���� �迭�� ���� �� ��ȯ

*/
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

unordered_map<string, string> parent;   // ����õ�ڿ� ��õ�� ���� ����
unordered_map<string, int> income;

void calculate(string seller, int amount) {

    if (amount <= 0)
        return;

    int present = amount * 0.1;
    calculate(parent[seller], present);
    income[seller] += (amount - present);
}

vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount) {
    vector<int> answer;

    for (int i = 0; i < enroll.size(); i++)  // N
        parent[enroll[i]] = referral[i];

    for (int i = 0; i < seller.size(); i++)  // N*logN
        calculate(seller[i], amount[i] * 100);

    for (int i = 0; i < enroll.size(); i++)  // N
        answer.push_back(income[enroll[i]]);

    return answer;
}