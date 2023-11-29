//
// Created by 陆泽辉 on 2022/7/25.
//

#ifndef LEETCODE_LEETCODE919_H
#define LEETCODE_LEETCODE919_H

#include "TreeNode.h"
#include <vector>

using namespace std;

class CBTInserter {
public:
    CBTInserter(TreeNode* root);

    int insert(int val);

    TreeNode* get_root();

private:
    TreeNode* mRoot;
    vector<TreeNode*> trees;
};


#endif //LEETCODE_LEETCODE919_H
