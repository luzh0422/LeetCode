//
// Created by 陆泽辉 on 2023/8/6.
//

#include "LeetCode24.h"

ListNode *LeetCode24::swapPairs(ListNode *head) {
    auto res = new ListNode();
    res->next = head;
    auto node = res;
    int tag = 0;
    while (node->next != nullptr && node->next->next != nullptr) {
        auto next = node->next;
        auto nextNext = node->next->next;
        next->next = nextNext->next;
        nextNext->next = next;
        node->next = nextNext;
        node = node->next->next;
    }
    return res->next;
}
