//
// Created by luzh on 2021/12/25.
//

#include "Solution1609.h"

#include <queue>

bool Solution1609::isEvenOddTree(TreeNode *root) {
    int level = 0;
    std::queue<TreeNode*> q;
    q.push(root);
    int count = 1;
    while (!q.empty()) {
        int temp = 0;
        int last = level % 2 == 0 ? INT_MIN : INT_MAX;
        for (int i = 0; i < count; i++) {
            TreeNode* node = q.front();
            q.pop();
            int val = node->val;
            if (level % 2 == 0 && (val % 2 == 0 || val <= last) || level % 2 == 1 && (val % 2 == 1 || val > last)) {
                return false;
            }
            last = val;
            auto left = node->left;
            auto right = node->right;
            if (left != nullptr) {
                temp++;
                q.push(left);
            }
            if (right != nullptr) {
                temp++;
                q.push(right);
            }
        }
        count = temp;
        level++;
    }
    return true;
}
