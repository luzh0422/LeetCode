//
// Created by 陆泽辉 on 2022/7/25.
//

#include "LeetCode919.h"
#include <queue>

CBTInserter::CBTInserter(TreeNode *root) {
    mRoot = root;
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()) {
        auto curr = q.front();
        q.pop();
        trees.push_back(curr);
        if (curr->left) {
            q.push(curr->left);
        }
        if (curr->right) {
            q.push(curr->right);
        }
    }
}

int CBTInserter::insert(int val) {
    TreeNode* curr = new TreeNode(val);
    trees.push_back(curr);
    int n = trees.size() - 2;
    TreeNode* parent = trees[n / 2];
    if (parent->left) {
        parent->right = curr;
    } else {
        parent->left = curr;
    }
    return parent->val;
}

TreeNode *CBTInserter::get_root() {
    return mRoot;
}
