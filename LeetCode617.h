//
// Created by 陆泽辉 on 2023/8/14.
//

#ifndef LEETCODE_LEETCODE617_H
#define LEETCODE_LEETCODE617_H

#include "TreeNode.h"

class LeetCode617 {
public:
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2);

private:
    void mergeTrees(TreeNode* root1, TreeNode* root2, TreeNode* root);
};


#endif //LEETCODE_LEETCODE617_H
