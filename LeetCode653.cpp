//
// Created by luzh on 2022/3/21.
//

#include <stack>
#include "LeetCode653.h"

bool LeetCode653::findTarget(TreeNode *root, int k) {
    mRoot = root;
    if (root == nullptr) {
        return false;
    }
    std::stack<TreeNode*> stk;
    stk.push(root);
    while (!stk.empty()) {
        auto currNode = stk.top();
        stk.pop();
        if (findTarget(k - currNode->val)) {
            return true;
        }
        if (currNode->left != nullptr) {
            stk.push(currNode->left);
        }
        if (currNode->right != nullptr) {
            stk.push(currNode->right);
        }
    }
    return false;
}

TreeNode* LeetCode653::findTarget(int k) {
    std::stack<TreeNode*> stk;
    stk.push(mRoot);
    while (!stk.empty()) {
        auto currNode = stk.top();
        stk.pop();
        int currVal = currNode->val;
        if (k == currVal) {
            return currNode;
        } else if (k < currVal && currNode->left != nullptr) {
            stk.push(currNode->left) ;
        } else if (k > currVal && currNode->right != nullptr) {
            stk.push(currNode->right);
        }
    }
    return nullptr;
}
