//
// Created by 陆泽辉 on 2022/6/2.
//

#include "LeetCode450.h"

TreeNode *LeetCode450::deleteNode(TreeNode *root, int key) {
    if (root == nullptr) {
        return nullptr;
    }
    if (root->val > key) {
        root->left = deleteNode(root->left, key);
        return root;
    }
    if (root->val < key) {
        root->right = deleteNode(root->right, key);
        return root;
    }
    /**
     * 找到需要删除的节点；
     */
    if (root->val == key) {
        if (!root->left && !root->right) {
            return nullptr;
        }
        if (!root->right) {
            return root->left;
        }
        if (!root->left) {
            return root->right;
        }
        /**
         * 找到右子树的最左侧节点；
         */
        TreeNode* successor = root->right;
        while (successor->left) {
            successor = successor->left;
        }
        /**
         * 删除右子树的最左侧节点；
         */
        root->right = deleteNode(root->right, successor->val);
        /**
         * 将删除的节点代替当前节点；
         */
        successor->right = root->right;
        successor->left = root->left;
        return successor;
    }
    return root;
}
