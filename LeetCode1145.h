//
// Created by 陆泽辉 on 2023/2/3.
//

#ifndef LEETCODE_LEETCODE1145_H
#define LEETCODE_LEETCODE1145_H

#include "TreeNode.h"

class LeetCode1145 {
public:
    bool btreeGameWinningMove(TreeNode* root, int n, int x);

private:
    int countNodes(TreeNode* node);
};


#endif //LEETCODE_LEETCODE1145_H
