//
// Created by luzh on 2022/1/16.
//

#include "Solution382.h"

Solution382::Solution382(ListNode *head) {
    ListNode* node = head;
    while (node != nullptr) {
        arr.emplace_back(node->val);
        node = node->next;
        n++;
    }
}

int Solution382::getRandom() {
    int index = random() % n;
    return arr[index];
}
