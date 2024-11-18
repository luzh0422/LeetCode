//
// Created by luzehui on 2023/12/4.
//

#ifndef LEETCODE_LEETCODE1038_H
#define LEETCODE_LEETCODE1038_H

#include "TreeNode.h"

class LeetCode1038 {
public:
    TreeNode* bstToGst(TreeNode* root);

private:
    int bstToGst(TreeNode* root, int val);
};


#endif //LEETCODE_LEETCODE1038_H
