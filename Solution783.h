//
// Created by luzh on 2021/4/13.
//

#ifndef LEETCODE_SOLUTION783_H
#define LEETCODE_SOLUTION783_H

#include "TreeNode.h"

class Solution783 {
public:
    Solution783() {}
    int minDiffInBST(TreeNode* root);

private:
    int findLeftMaxVal(TreeNode* root);
    int findRightMinVal(TreeNode* root);
};


#endif //LEETCODE_SOLUTION783_H
