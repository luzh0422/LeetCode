//
// Created by 陆泽辉 on 2023/8/5.
//

#include "LeetCode21.h"

ListNode *LeetCode21::mergeTwoLists(ListNode *list1, ListNode *list2) {
    ListNode* res = new ListNode();
    auto node = res;
    while (list1 != nullptr && list2 != nullptr) {
        if (list1->val <= list2->val) {
            node->next = list1;
            list1 = list1->next;
        } else {
            node->next = list2;
            list2 = list2->next;
        }
        node = node->next;
    }
    if (list1 != nullptr) {
        node->next = list1;
    }
    if (list2 != nullptr) {
        node->next = list2;
    }
    return res->next;
}
