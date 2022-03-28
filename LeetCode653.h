//
// Created by luzh on 2022/3/21.
//

#ifndef LEETCODE_LEETCODE653_H
#define LEETCODE_LEETCODE653_H

#include "TreeNode.h"

class LeetCode653 {
public:
    bool findTarget(TreeNode* root, int k);

private:
    TreeNode* mRoot =  nullptr;
    TreeNode* findTarget(int k);
};


#endif //LEETCODE_LEETCODE653_H
