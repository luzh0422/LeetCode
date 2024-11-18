//
// Created by luzehui on 2024/2/7.
//

#include "LeetCode2641.h"
#include <queue>

TreeNode *LeetCode2641::replaceValueInTree(TreeNode *root) {
    vector<int> sums = {};
    bfs1(root, sums);
    bfs2(root, sums);
    return root;
}

void LeetCode2641::bfs1(TreeNode *root, vector<int> &sums) {
    int count = 1;
    std::queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        int temp = 0, sum = 0;
        for (int i = 0; i < count; i++) {
            auto node = q.front();
            q.pop();
            sum += node->val;
            if (node->left) {
                q.push(node->left);
                temp++;
            }
            if (node->right) {
                q.push(node->right);
                temp++;
            }
        }
        sums.push_back(sum);
        count = temp;
    }
}

void LeetCode2641::bfs2(TreeNode *root, vector<int> &sums) {
    int count = 1;
    queue<TreeNode*> q;
    q.push(root);
    root->val = 0;
    int level = 0;
    while (!q.empty()) {
        if (level == sums.size() - 1) {
            break;
        }
        int temp = 0, sum = sums[++level];
        for (int i = 0; i < count; i++) {
            auto node = q.front();
            q.pop();
            int leftValCache = 0;
            if (node->left) {
                leftValCache = node->left->val;
                node->left->val = sum - node->left->val;
                if (node->right) {
                    node->left->val = node->left->val - node->right->val;
                }
                q.push(node->left);
                temp++;
            }
            if (node->right) {
                node->right->val = sum - node->right->val - leftValCache;
                q.push(node->right);
                temp++;
            }
        }
        count = temp;
    }
}
