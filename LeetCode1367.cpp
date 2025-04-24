//
// Created by luzehui on 24-12-30.
//

#include "LeetCode1367.h"

bool LeetCode1367::isSubPath(ListNode *head, TreeNode *root) {
    if (!root) {
        return false;
    }
    if (root->val == head->val && check(head, root)) {
            return true;
    }
    return isSubPath(head, root->left) || isSubPath(head, root->right);
}

bool LeetCode1367::check(ListNode *head, TreeNode *root) {
    if (!head) {
        return true;
    }
    if (!root) {
        return false;
    }
    if (head->val == root->val) {
        return check(head->next, root->left) || check(head->next, root->right);
    }
    return false;
}
