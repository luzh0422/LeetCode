//
// Created by luzehui on 2024/3/12.
//

#ifndef LEETCODE_LEETCODE1261_H
#define LEETCODE_LEETCODE1261_H

#include "TreeNode.h"
#include <unordered_set>

using namespace std;

class FindElements {
public:
    FindElements(TreeNode* root);

    bool find(int target);

private:
    void reconstructorTree(TreeNode* root);
    unordered_set<int> uS;
};


#endif //LEETCODE_LEETCODE1261_H
