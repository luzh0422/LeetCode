//
// Created by 陆泽辉 on 2023/7/31.
//

#include "LeetCode142.h"
#include <unordered_set>

ListNode *LeetCode142::detectCycle(ListNode *head) {
    std::unordered_set<ListNode*> uS;
    auto node = head;
    while (node != NULL) {
        if (uS.count(node)) {
            return node;
        }
        uS.insert(node);
        node = node->next;
    }
    return NULL;
}
