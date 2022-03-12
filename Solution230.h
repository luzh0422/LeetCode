//
// Created by luzh on 2021/10/17.
//

#ifndef LEETCODE_SOLUTION230_H
#define LEETCODE_SOLUTION230_H

#include "TreeNode.h"
#include <vector>

using namespace std;

class Solution230 {
public:
    int kthSmallest(TreeNode* root, int k);

private:
    void kthSmallest(TreeNode* root, vector<int>& rootVals);
};


#endif //LEETCODE_SOLUTION230_H
