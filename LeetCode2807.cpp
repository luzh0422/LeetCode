//
// Created by luzehui on 2024/1/6.
//

#include "LeetCode2807.h"
#include <numeric>

using namespace std;

ListNode *LeetCode2807::insertGreatestCommonDivisors(ListNode *head) {
    auto node = head;
    while (node != nullptr && node->next != nullptr) {
        int val = commonDivisor(node->val, node->next->val);
        auto next = node->next;
        node->next = new ListNode(val);
        node->next->next = node->next;
        node = node->next->next;
    }
    return head;
}

int LeetCode2807::commonDivisor(int num1, int num2) {
    int val1 = max(num1, num2);
    int val2 = min(num1, num2);
    if (val1 % val2 == 0) {
        return val2;
    }
    return commonDivisor(val1, val1 % val2);
}
