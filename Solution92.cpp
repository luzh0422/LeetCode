//
// Created by luzh on 2021/3/18.
//

#include "Solution92.h"
#include <stack>

ListNode * Solution92::reverseBetween(ListNode *head, int left, int right) {
    int index = 1;
    std::stack<int> stk;
    ListNode* node = head;
    while (node != NULL) {
        if (index >= left && index <= right) {
            stk.push(node->val);
        }
        node = node->next;
        index++;
    }
    node = head;
    index = 1;
    while (node != NULL) {
        if (index >= left && index <= right) {
            node->val = stk.top();
            stk.pop();
        }
        node = node->next;
        index++;
    }
    return head;
}
