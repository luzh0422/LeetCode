//
// Created by 陆泽辉 on 2022/5/16.
//

#include "LeetCode04_06.h"
#include <stack>

using namespace std;

TreeNode *LeetCode04_06::inorderSuccessor(TreeNode *root, TreeNode *p) {
    stack<TreeNode*> stk;
    TreeNode *prev = nullptr, *curr = root;
    while (!stk.empty() || curr != nullptr) {
        while (curr != nullptr) {
            stk.push(curr);
            curr = curr->left;
        }
        curr = stk.top(); // 最左子树的节点；
        stk.pop();
        if (prev == p) {
            return curr;
        }
        prev = curr;
        curr = curr->right;
    }
    return nullptr;
}
