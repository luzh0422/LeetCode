//
// Created by 陆泽辉 on 2022/5/16.
//

#ifndef LEETCODE_LEETCODE04_06_H
#define LEETCODE_LEETCODE04_06_H

#include "TreeNode.h"

class LeetCode04_06 {
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p);

private:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p, TreeNode* parent);
};


#endif //LEETCODE_LEETCODE04_06_H
