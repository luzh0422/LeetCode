//
// Created by 陆泽辉 on 2022/9/2.
//

#ifndef LEETCODE_LEETCODE687_H
#define LEETCODE_LEETCODE687_H

#include "TreeNode.h"

class LeetCode687 {
public:
    int longestUnivaluePath(TreeNode* root);

private:
    int longestUnivaluePath(TreeNode* root, int &res);
};


#endif //LEETCODE_LEETCODE687_H
