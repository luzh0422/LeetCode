//
// Created by 陆泽辉 on 2023/7/31.
//

#include "LeetCode143.h"
#include <queue>
#include <stack>

void LeetCode143::reorderList(ListNode *head) {

    std::stack<ListNode*> stk;
    std::queue<ListNode*> q;
    auto node = head;
    int size = 0;
    while (node != NULL) {
        stk.push(node);
        q.push(node);
        auto pre = node;
        node = node->next;
        pre->next = NULL;
        size++;
    }
    node = head;
    q.pop();
    for (int i = 1; i < size; ) {
        if (!stk.empty()) {
            ListNode* next = stk.top();
            stk.pop();
            node->next = next;
            node = node->next;
        }
        i++;
        if (i >= size) {
            break;
        }
        if (!q.empty()) {
            ListNode* nextNext = q.front();
            q.pop();
            node->next = nextNext;
            node = node->next;
        }
        i++;
    }
    return;
}
