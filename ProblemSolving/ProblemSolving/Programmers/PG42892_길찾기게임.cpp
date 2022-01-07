#include <string>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct _NODE {
    int idx;
    _NODE* left;
    _NODE* right;
} Node;

struct INFO {
    int x, y, idx;
};

Node* root;
vector<INFO> info;
vector<int> pre;
vector<int> post;

bool cmp(INFO a, INFO b) {
    return a.x < b.x;
}

int getMaxYIndex(int left, int right) {
    int maxY = info[left].y;
    int maxIdx = left;
    for (int i = left + 1; i <= right; i++) {
        if (info[i].y > maxY) {
            maxY = info[i].y;
            maxIdx = i;
        }
    }
    return maxIdx;
}

Node* makeTree( int left, int right) {
    if (left > right)
        return NULL;

    Node* newNode = new Node();
    newNode->idx = getMaxYIndex(left, right);
    newNode->left = makeTree(left, newNode->idx - 1);
    newNode->right = makeTree(newNode->idx + 1, right);
    return newNode;
}

void preOrder(Node* node) {
    if (node == NULL)
        return;

    pre.push_back(info[node->idx].idx);
    preOrder(node->left);
    preOrder(node->right);
}

void postOrder(Node* node) {
    if (node == NULL)
        return;

    postOrder(node->left);
    postOrder(node->right);
    post.push_back(info[node->idx].idx);
}

vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
    vector<vector<int>> answer;

    for (int i = 0; i < nodeinfo.size(); i++) 
        info.push_back({ nodeinfo[i][0], nodeinfo[i][1], i + 1 });

    sort(info.begin(), info.end(), cmp);

    Node* root = new Node();
    root->idx = getMaxYIndex(0, nodeinfo.size() - 1);
    root->left = makeTree(0, root->idx - 1);
    root->right = makeTree(root->idx+1, nodeinfo.size() - 1);

    // ¼øÈ¸
    preOrder(root);
    postOrder(root);

    answer.push_back(pre);
    answer.push_back(post);

    return answer;
}

int main() {

    solution({ {5,3},{11,5},{13,3},{3,5},{6,1},{1,3},{8,6},{7,2},{2,2} });

    return 0;
}