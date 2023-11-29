//
// Created by 陆泽辉 on 2022/3/19.
//

#include "LeetCode606.h"

string LeetCode606::tree2str(TreeNode *root) {
    string ret = "";
    if (root == nullptr) {
        return ret;
    }
    ret += to_string(root->val);
    if (root->left != nullptr) {
        ret += "(";
        ret += tree2str(root->left);
        ret += ")";
    }
    if (root->right != nullptr) {
        if (root->left == nullptr) {
            ret += "()";
        }
        ret += "(";
        ret += tree2str(root->right);
        ret += ")";
    }
    return ret;
}
