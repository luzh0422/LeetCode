//
// Created by 陆泽辉 on 2023/7/2.
//

#include "LeetCode2.h"

ListNode *LeetCode2::addTwoNumbers(ListNode *l1, ListNode *l2) {
    ListNode* root = new ListNode(-1);
    ListNode* node = root;
    int num = 0, temp = 0;
    while (l1 != nullptr && l2 != nullptr) {
        num = l1->val + l2->val + temp;
        temp = num / 10;
        num %= 10;
        node->next = new ListNode(num);
        node = node->next;
        l1 = l1->next;
        l2 = l2->next;
    }
    while (l1 != nullptr) {
        num = l1->val + temp;
        temp = num / 10;
        num %= 10;
        node->next = new ListNode(num);
        node = node->next;
        l1 = l1->next;
    }
    while (l2 != nullptr) {
        num = l2->val + temp;
        temp = num / 10;
        num %= 10;
        node->next = new ListNode(num);
        node = node->next;
        l2 = l2->next;
    }
    if (temp != 0) {
        node->next = new ListNode(temp);
        node = node->next;
    }
    return root->next;
}
