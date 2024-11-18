//
// Created by luzehui on 2024/1/15.
//

#include "LeetCode82.h"

ListNode *LeetCode82::deleteDuplicates(ListNode *head) {
    while (head != nullptr && head->next != nullptr && head->val == head->next->val) {
        auto val = head->val;
        auto node = head;
        while (node != nullptr && node->val == val) {
            node = node->next;
        }
        head = node;
    }
    auto node = head;
    while (node != nullptr) {
        auto next = node->next;
        while (next != nullptr && next->next != nullptr && next->val == next->next->val) {
            int val = next->val;
            while (next != nullptr && next->val == val) {
                next = next->next;
            }
        }
        node->next = next;
        node = node->next;
    }
    return head;
}
