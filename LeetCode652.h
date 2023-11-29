//
// Created by 陆泽辉 on 2022/9/5.
//

#ifndef LEETCODE_LEETCODE652_H
#define LEETCODE_LEETCODE652_H

#include <vector>
#include <unordered_map>
#include <string>
#include "TreeNode.h"

using namespace std;

class LeetCode652 {
public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root);
    string findDuplicateSubtrees(TreeNode* root, vector<TreeNode*>& ret, unordered_map<string, int>& record);

private:
    bool isDuplicateTrees(TreeNode* root1, TreeNode* root2);
};


#endif //LEETCODE_LEETCODE652_H
