//
// Created by 陆泽辉 on 2023/1/30.
//

#include "LeetCode1669.h"

ListNode *LeetCode1669::mergeInBetween(ListNode *list1, int a, int b, ListNode *list2) {
    auto node1 = list1, node2 = list1;
    auto node3 = list2;
    int index = 0;
    while (node1->next != nullptr) {
        if (index + 1 == a) {
            break;
        }
        node1 = node1->next;
    }
    node2 = node1;
    while (node2 != nullptr) {
        if (index == b) {
            node2 = node2->next;
            break;
        }
        node2 = node2->next;
    }
    node1->next = list2;
    while (node3->next != nullptr) {
        node3 = node3->next;
    }
    node3->next = node2;
    return list1;
}
