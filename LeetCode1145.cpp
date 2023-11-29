//
// Created by 陆泽辉 on 2023/2/3.
//

#include "LeetCode1145.h"
#include <queue>

using namespace std;

bool LeetCode1145::btreeGameWinningMove(TreeNode *root, int n, int x) {
    auto node = root;
    queue<TreeNode*> q;
    q.push(node);
    while (!q.empty()) {
        node = q.front();
        q.pop();
        if (node->val == x) {
            break;
        }
        if (node->left) {
            q.push(node->left);
        }
        if (node->right) {
            q.push(node->right);
        }
    }
    int leftCount = countNodes(node->left);
    int rightCount = countNodes(node->right);
    int nodeParentCount = n - 1 - leftCount - rightCount;
    int target = n / 2 + 1;
    return leftCount > target || rightCount > target || nodeParentCount > target;
}

int LeetCode1145::countNodes(TreeNode *node) {
    queue<TreeNode*> q;
    q.push(node);
    int ret = 0;
    while (!q.empty()) {
        auto temp = q.front();
        q.pop();
        ret++;
        if (temp->left) {
            q.push(temp->left);
        }
        if (temp->right) {
            q.push(temp->right);
        }
    }
    return ret;
}
