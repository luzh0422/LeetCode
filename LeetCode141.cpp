//
// Created by 陆泽辉 on 2023/7/31.
//

#include "LeetCode141.h"

bool LeetCode141::hasCycle(ListNode *head) {
    auto nextNode = head, nextNextNode = head->next;
    while (nextNode != nullptr) {
        if (nextNode == nextNextNode) {
            return true;
        }
        nextNode = nextNode->next;
        if (nextNextNode != nullptr && nextNextNode->next != nullptr) {
            nextNextNode = nextNextNode->next->next;
        }
    }
    return false;
}
