//
// Created by luzehui on 2024/2/29.
//

#ifndef LEETCODE_LEETCODE2476_H
#define LEETCODE_LEETCODE2476_H

#include <vector>
#include "TreeNode.h"

using namespace std;

class LeetCode2476 {
public:
    vector<vector<int>> closestNodes(TreeNode* root, vector<int>& queries);

private:
    void constructSortedArray(TreeNode* root, vector<int>& sortedArray);
};


#endif //LEETCODE_LEETCODE2476_H
