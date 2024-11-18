//
// Created by luzehui on 2024/8/4.
//

#ifndef LEETCODE_LEETCODE572_H
#define LEETCODE_LEETCODE572_H

#include "TreeNode.h"

class LeetCode572 {
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot);

private:
    bool isSametree(TreeNode* root1, TreeNode* root2);
};


#endif //LEETCODE_LEETCODE572_H
