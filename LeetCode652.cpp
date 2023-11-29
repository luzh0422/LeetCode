//
// Created by 陆泽辉 on 2022/9/5.
//

#include "LeetCode652.h"

vector<TreeNode *> LeetCode652::findDuplicateSubtrees(TreeNode *root) {
    vector<TreeNode*> ret = {};
    unordered_map<string, int> record = {};
    findDuplicateSubtrees(root, ret, record);
    return ret;
}

/**
 * 利用树形结构的序列化，判断树形结构的结构和值是否相同。
 */
string LeetCode652::findDuplicateSubtrees(TreeNode *root, vector<TreeNode *> &ret, unordered_map<string, int> &record) {
    string leftPath = "#", rightPath = "#";
    if (root->left) {
        leftPath = leftPath + findDuplicateSubtrees(root->left, ret, record);
    }
    if (root->right) {
        rightPath = rightPath + findDuplicateSubtrees(root->right, ret, record);
    }
    string prePath = to_string(root->val) + leftPath + rightPath;
    if (record.count(prePath)) {
        if (record[prePath] == 1) {
            record[prePath]++;
            ret.emplace_back(root);
        }
    } else {
       record.emplace(prePath, 1);
    }
    return prePath;
}

bool LeetCode652::isDuplicateTrees(TreeNode *root1, TreeNode *root2) {
    bool ret = true;
    if (root1->val != root2->val) {
        return false;
    }
    if (root1->left && root2->left) {
        ret &= isDuplicateTrees(root1->left, root2->left);
    } else {
        return false;
    }
    if (root1->right && root2->right) {
        ret &= isDuplicateTrees(root1->right, root2->right);
    } else {
        return false;
    }
    return ret;
}

