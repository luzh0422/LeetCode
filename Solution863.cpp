//
// Created by luzh on 2021/7/28.
//

#include "Solution863.h"
#include <queue>

void Solution863::findParent(TreeNode *root, TreeNode* parent) {
    if (parent != nullptr) {
        this->parents[root] = parent;
    }
    if (root->left != nullptr) {
        findParent(root->left, root);
    }
    if (root->right != nullptr) {
        findParent(root->right, root);
    }
}

void Solution863::findAns(TreeNode *root, TreeNode *from, int distance, int k, vector<int>& ans) {
    if (distance == k) {
        ans.push_back(root->val);
        return;
    }
    if (root->left != nullptr && root->left != from) {
        findAns(root->left, root, distance + 1, k, ans);
    }
    if (root->right != nullptr && root->right != from) {
        findAns(root->right, root, distance + 1, k, ans);
    }
    if (this->parents.count(root) && this->parents[root] != from) {
        findAns(this->parents[root], root, distance + 1, k, ans);
    }
}

vector<int> Solution863::distanceK(TreeNode *root, TreeNode *target, int k) {
    findParent(root, nullptr);
    vector<int> ans;
    findAns(root, nullptr, 0, k, ans);
    return ans;
}
