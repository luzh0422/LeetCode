//
// Created by luzehui on 2024/1/3.
//

#include "LeetCode2487.h"
#include <stack>

using namespace std;

ListNode *LeetCode2487::removeNodes(ListNode *head) {
    stack<int> stk1;
    stack<int> stk2;
    auto node = head;
    while (node != nullptr) {
        stk1.push(node->val);
        node = node->next;
    }
    int rightMaxVal = -1;
    while (!stk1.empty()) {
        int currVal = stk1.top();
        stk1.pop();
        if (currVal >= rightMaxVal) {
            stk2.push(currVal);
            rightMaxVal = currVal;
        }
    }
    head = new ListNode();
    node = head;
    while (!stk2.empty()) {
        int val = stk2.top();
        stk2.pop();
        node->next = new ListNode(val);
        node = node->next;
    }
    return head->next;
}
