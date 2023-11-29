//
// Created by 陆泽辉 on 2022/8/20.
//

#ifndef LEETCODE_LEETCODE645_H
#define LEETCODE_LEETCODE645_H

#include "TreeNode.h"
#include <vector>

using namespace std;

class LeetCode645 {
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums);

private:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums, int left, int right);
};


#endif //LEETCODE_LEETCODE645_H
