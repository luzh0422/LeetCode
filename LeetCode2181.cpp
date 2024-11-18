//
// Created by luzehui on 2024/9/9.
//

#include "LeetCode2181.h"

ListNode *LeetCode2181::mergeNodes(ListNode *head) {
    int currVal = 0;
    ListNode* res = new ListNode(0);
    auto node = head, node2 = res;
    while (node != nullptr) {
        if (node->val == 0) {
            if (currVal != 0) {
                node2->next = new ListNode(currVal);
                node2 = node2->next;
            }
            currVal = 0;
        } else {
            currVal += node->val;
        }
        node = node->next;
    }
    if (currVal != 0) {
        node2->next = new ListNode(currVal);
        node2 = node2->next;
    }
    return res->next;
}
