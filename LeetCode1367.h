//
// Created by luzehui on 24-12-30.
//

#ifndef LEETCODE_LEETCODE1367_H
#define LEETCODE_LEETCODE1367_H

#include "TreeNode.h"
#include "ListNode.h"

class LeetCode1367 {
public:
    bool isSubPath(ListNode* head, TreeNode* root);

private:
    bool check(ListNode* head, TreeNode* root);
};


#endif //LEETCODE_LEETCODE1367_H
