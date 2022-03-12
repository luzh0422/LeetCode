#ifndef LEETCODE_SOLUTION173_H
#define LEETCODE_SOLUTION173_H

#include "TreeNode.h"

#include <vector>

using namespace std;

class BSTIterator {
public:
    BSTIterator(TreeNode* root);
    int next();
    bool hasNext();

private:
    int curr = 0;
    int length = 0;
    vector<int> store;
    void inOrder(TreeNode* root);

};

#endif
