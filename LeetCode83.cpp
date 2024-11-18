//
// Created by luzehui on 2024/1/14.
//

#include "LeetCode83.h"

ListNode *LeetCode83::deleteDuplicates(ListNode *head) {
    auto node = head;
    while (node != nullptr) {
        auto next = node->next;
        while (next != nullptr && next->val == node->val) {
            next = next->next;
        }
        node->next = next;
        node = node->next;
    }
    return head;
}
