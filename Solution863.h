//
// Created by luzh on 2021/7/28.
//

#ifndef LEETCODE_SOLUTION863_H
#define LEETCODE_SOLUTION863_H

#include <vector>
#include <unordered_map>
#include "TreeNode.h"

using namespace std;

class Solution863 {
private:
    void findParent(TreeNode* root, TreeNode* parent);
    void findAns(TreeNode* root, TreeNode* from, int distance, int k, vector<int>& ans);
    unordered_map<TreeNode*, TreeNode*> parents;

public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k);
};


#endif //LEETCODE_SOLUTION863_H
