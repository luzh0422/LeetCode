//
// Created by 陆泽辉 on 2023/5/30.
//

#ifndef LEETCODE_LEETCODE1110_H
#define LEETCODE_LEETCODE1110_H

#include "TreeNode.h"
#include <vector>
#include <unordered_set>

using namespace std;

class LeetCode1110 {
public:
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete);

private:
    void delNodes(TreeNode* root, TreeNode* parent, unordered_set<int>& cache, vector<TreeNode*>& res, int direction);
};


#endif //LEETCODE_LEETCODE1110_H
