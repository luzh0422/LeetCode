//
// Created by luzehui on 2024/1/6.
//

#ifndef LEETCODE_LEETCODE2807_H
#define LEETCODE_LEETCODE2807_H

#include "ListNode.h"

class LeetCode2807 {
public:
    ListNode* insertGreatestCommonDivisors(ListNode* head);

private:
    int commonDivisor(int num1, int num2);
};


#endif //LEETCODE_LEETCODE2807_H
