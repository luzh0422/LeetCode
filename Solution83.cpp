//
// Created by luzh on 2021/3/27.
//

#include "Solution83.h"

ListNode * Solution83::deleteDuplicates(ListNode *head) {
//    while (head != NULL && head->next != NULL) {
//        if (head->val == head->next->val) {
//            head = head->next;
//        } else {
//            break;
//        }
//    }
    ListNode* node = head;
    while (node != nullptr && node->next != nullptr) {
        if (node->val == node->next->val) {
            node->next = node->next->next;
        } else {
            node = node->next;
        }
    }
    return head;
}
