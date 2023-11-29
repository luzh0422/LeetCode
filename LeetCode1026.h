//
// Created by 陆泽辉 on 2023/4/18.
//

#ifndef LEETCODE_LEETCODE1026_H
#define LEETCODE_LEETCODE1026_H

#include "TreeNode.h"

class LeetCode1026 {
public:
    int maxAncestorDiff(TreeNode* root);

private:
    int maxAncestorDiff(TreeNode* root, int minVal, int maxVal);
};


#endif //LEETCODE_LEETCODE1026_H
