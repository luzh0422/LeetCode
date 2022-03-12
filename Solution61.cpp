//
// Created by luzh on 2021/3/27.
//

#include "Solution61.h"

ListNode * Solution61::rotateRight(ListNode *head, int k) {
    int length = 0;
    ListNode* node = head;
    while (node != nullptr) {
        node = node->next;
        length++;
    }
    if (length == 0) {
        return nullptr;
    }
    k %= length;
    if (k == 0) {
        return head;
    }
    int front = length - k;
    int step = 1;
    node = head;
    while (step < front) {
        node = node->next;
        step++;
    }
    ListNode* ans = node->next;
    ListNode* node1 = node->next;
    while (node1->next != nullptr) {
        node1 = node1->next;
    }
    node->next = nullptr;
    node1->next = head;
    return ans;
}
