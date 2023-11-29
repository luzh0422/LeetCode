//
// Created by 陆泽辉 on 2023/7/3.
//

#include "LeetCode445.h"

#include <stack>

using namespace std;

ListNode *LeetCode445::addTwoNumbers(ListNode *l1, ListNode *l2) {
    stack<int> s1, s2;
    while (l1 != nullptr) {
        s1.push(l1->val);
        l1 = l1->next;
    }
    while (l2 != nullptr) {
        s2.push(l2->val);
        l2 = l2->next;
    }
    stack<int> s3;
    int num = 0, temp = 0;
    while (!s1.empty() && !s2.empty()) {
        num = s1.top() + s2.top() + temp;
        temp = num / 10;
        num %= 10;
        s1.pop();
        s2.pop();
        s3.push(num);
    }
    while (!s1.empty()) {
        num = s1.top() + temp;
        temp = num / 10;
        num %= 10;
        s1.pop();
        s3.push(num);
    }
    while (!s2.empty()) {
        num = s2.top() + temp;
        temp = num / 10;
        num %= 10;
        s2.pop();
        s3.push(num);
    }
    if (temp != 0) {
        s3.push(temp);
    }
    ListNode* res = new ListNode(-1);
    ListNode* node = res;
    while (!s3.empty()) {
        node->next = new ListNode(s3.top());
        s3.pop();
        node = node->next;
    }
    return res->next;
}
