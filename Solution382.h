//
// Created by luzh on 2022/1/16.
//

#ifndef LEETCODE_SOLUTION382_H
#define LEETCODE_SOLUTION382_H

#include "ListNode.h"
#include <vector>
using namespace std;

class Solution382 {
public:
    Solution382(ListNode* head);
    int getRandom();

private:
    vector<int> arr;
    int n = 0;
};


#endif //LEETCODE_SOLUTION382_H
