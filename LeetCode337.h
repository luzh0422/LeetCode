//
// Created by 陆泽辉 on 2023/9/18.
//

#ifndef LEETCODE_LEETCODE337_H
#define LEETCODE_LEETCODE337_H

#include "TreeNode.h"

#include <vector>
#include <unordered_map>

using namespace std;

class LeetCode337 {
public:
    int rob(TreeNode* root);

private:
    int rob(TreeNode* root, int tag, unordered_map<TreeNode*, int>& uM);
};


#endif //LEETCODE_LEETCODE337_H
