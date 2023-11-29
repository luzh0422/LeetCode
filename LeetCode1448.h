//
// Created by 陆泽辉 on 2023/8/25.
//

#ifndef LEETCODE_LEETCODE1448_H
#define LEETCODE_LEETCODE1448_H

#include "TreeNode.h"

class LeetCode1448 {
public:
    int goodNodes(TreeNode* root);

private:
    int goodNodes(TreeNode* root, int currMaxVal);
};


#endif //LEETCODE_LEETCODE1448_H
