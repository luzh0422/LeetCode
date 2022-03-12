//
// Created by luzh on 2021/6/5.
//

#include "Solution203.h"
ListNode * Solution203::removeElements(ListNode *head, int val) {
    while (head != nullptr) {
        if (head->val == val) {
            head = head->next;
        } else {
            break;
        }
    }
    if (head == nullptr) {
        return head;
    }
    ListNode* curr = head;
    ListNode* next = curr->next;
    while (next != nullptr) {
        if (next->val == val) {
            curr->next = next->next;
        } else {
            curr = next;
        }
        next = curr->next;
    }
    return head;
}
