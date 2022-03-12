//
// Created by luzh on 2021/11/2.
//

#include "Solution237.h"

void Solution237::deleteNode(ListNode *node) {
    ListNode* nextNode = node->next;
    if (nextNode == nullptr) {
        return;
    }
    node->val = nextNode->val;
    node->next = nextNode->next;
    return;
}
