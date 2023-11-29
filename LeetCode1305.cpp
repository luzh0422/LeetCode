//
// Created by 陆泽辉 on 2022/5/1.
//

#include "LeetCode1305.h"

vector<int> LeetCode1305::getAllElements(TreeNode *root1, TreeNode *root2) {
    vector<int> arr1, arr2;
    inorder(root1, arr1);
    inorder(root2, arr2);
    int index1 = 0, index2 = 0, n1 = arr1.size(), n2 = arr2.size();
    vector<int> ret;
    while (index1 < n1 && index2 < n2) {
        if (arr1[index1] < arr2[index2]) {
            ret.push_back(arr1[index1]);
            index1++;
        } else {
            ret.push_back(arr2[index2]);
            index2++;
        }
    }
    while (index1 < n1) {
        ret.push_back(arr1[index1]);
        index1++;
    }
    while (index2 < n2) {
        ret.push_back(arr2[index2]);
        index2++;
    }
    return ret;
}

void LeetCode1305::inorder(TreeNode *root, vector<int> &arr) {
    if (root->left != nullptr) {
        inorder(root->left, arr);
    }
    arr.push_back(root->val);
    if (root->right != nullptr) {
        inorder(root->right, arr);
    }
}
