//
// Created by luzehui on 2024/2/27.
//

#ifndef LEETCODE_LEETCODE235_H
#define LEETCODE_LEETCODE235_H

#include "TreeNode.h"

class LeetCode235 {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q);

private:
    TreeNode* lowestCommonAncestor(TreeNode* root, int minVal, int maxVal);
};


#endif //LEETCODE_LEETCODE235_H
