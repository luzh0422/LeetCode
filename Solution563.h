//
// Created by luzh on 2021/11/18.
//

#ifndef LEETCODE_SOLUTION563_H
#define LEETCODE_SOLUTION563_H

#include "TreeNode.h"
#include <unordered_map>

using namespace std;

class Solution563 {
public:
    int findTilt(TreeNode* root);

private:
    int sum(TreeNode* root);
    unordered_map<TreeNode*, int> sums = {};
};


#endif //LEETCODE_SOLUTION563_H
