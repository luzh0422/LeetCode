//
// Created by 陆泽辉 on 2022/6/19.
//

#ifndef LEETCODE_LEETCODE508_H
#define LEETCODE_LEETCODE508_H

#include <vector>
#include <unordered_map>
#include "TreeNode.h"

using namespace std;

class LeetCode508 {
public:
    vector<int> findFrequentTreeSum(TreeNode* root);

private:
    int findFrequentTreeSum(TreeNode* root, unordered_map<int, int>& uM);
};


#endif //LEETCODE_LEETCODE508_H
