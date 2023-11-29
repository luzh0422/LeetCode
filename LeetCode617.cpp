//
// Created by 陆泽辉 on 2023/8/14.
//

#include "LeetCode617.h"

TreeNode *LeetCode617::mergeTrees(TreeNode *root1, TreeNode *root2) {
    if (root1 == nullptr && root2 == nullptr) {
        return nullptr;
    }
    TreeNode* root = new TreeNode();
    mergeTrees(root1, root2, root);
    return root;
}

void LeetCode617::mergeTrees(TreeNode *root1, TreeNode *root2, TreeNode *root) {
    if (root1 == nullptr && root2 == nullptr) {
        return;
    }
    if (root1 != nullptr && root2 != nullptr) {
        root->val += root1->val;
        root->val += root2->val;
        if (root1->left != nullptr || root2->left != nullptr) {
            root->left = new TreeNode();
            mergeTrees(root1->left, root2->left, root->left);
        }
        if (root1->right != nullptr || root2->right != nullptr) {
            root->right = new TreeNode();
            mergeTrees(root1->right, root2->right, root->right);
        }
    } else if (root1 != nullptr) {
        root->val += root1->val;
        if (root1->left != nullptr) {
            root->left = new TreeNode();
            mergeTrees(root1->left, nullptr, root->left);
        }
        if (root1->right != nullptr) {
            root->right = new TreeNode();
            mergeTrees(root1->right, nullptr, root->right);
        }
    } else if (root2 != nullptr) {
        root->val += root2->val;
        if (root2->left != nullptr) {
            root->left = new TreeNode();
            mergeTrees(nullptr, root2->left, root->left);
        }
        if (root2->right != nullptr) {
            root->right = new TreeNode();
            mergeTrees(nullptr, root2->right, root->right);
        }
    }
}
