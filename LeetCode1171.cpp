//
// Created by 陆泽辉 on 2023/6/11.
//

#include "LeetCode1171.h"
#include <unordered_map>

using namespace std;

ListNode *LeetCode1171::removeZeroSumSublists(ListNode *head) {
    ListNode* res = new ListNode(0);
    res->next = head;
    int curr = 0;
    unordered_map<int, ListNode*> uM;
    for (auto node = res; node != nullptr; node = node->next) {
        curr += node->val;
        uM[curr] = node;
    }
    curr = 0;
    for (auto node = res; node != nullptr; node = node->next) {
        curr += node->val;
        node->next = uM[curr]->next;
    }
    return res->next;
}
