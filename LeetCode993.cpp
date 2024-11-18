//
// Created by luzehui on 2024/2/8.
//

#include "LeetCode993.h"
#include <queue>
#include <vector>

using namespace std;

bool LeetCode993::isCousins(TreeNode *root, int x, int y) {
    queue<TreeNode*> q;
    q.push(root);
    int count = 1;
    while (!q.empty()) {
        vector<TreeNode*> parents{};
        int tag = 0, temp = 0;
        for (int i = 0; i < count; i++) {
            auto node = q.front();
            q.pop();
            if (node->left) {
                if (node->left->val == x || node->left->val == y) {
                    tag++;
                    parents.push_back(node);
                }
                q.push(node->left);
                temp++;
            }
            if (node->right) {
                if (node->right->val == x || node->right->val == y) {
                    tag++;
                    parents.push_back(node);
                }
                q.push(node->right);
                temp++;
            }
            if (tag == 2) {
                return parents[0] != parents[1];
            }
        }
        count = temp;
    }
    return false;
}

