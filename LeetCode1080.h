//
// Created by 陆泽辉 on 2023/5/22.
//

#ifndef LEETCODE_LEETCODE1080_H
#define LEETCODE_LEETCODE1080_H

#include "TreeNode.h"

class LeetCode1080 {
public:
    TreeNode* sufficientSubset(TreeNode* root, int limit);

private:
    int sufficientSubset(TreeNode* root, int limit, int curr);
};


#endif //LEETCODE_LEETCODE1080_H
