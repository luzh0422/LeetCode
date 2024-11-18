//
// Created by luzehui on 2023/12/19.
//

#include "Mian2.h"
#include <stack>

struct ListNode {
    int val = 0;
    ListNode* next = nullptr;
};

list<int> Mian2::revertList(list<int> &l, int begin, int end) {
    int index = 0;
    list<int> node;
    auto iter = l.begin();
    for (; index < begin && iter != l.end(); index++) {
        node.push_back(*iter);
        iter++;
    }
    stack<int> stk;
    for (; index <= end && iter != l.end(); index++) {
        stk.push(*iter);
        iter++;
    }
    while (!stk.empty()) {
        auto val = stk.top();
        stk.pop();
        node.push_back(val);
    }
    while (iter != l.end()) {
        node.push_back(*iter);
        iter++;
    }
    return node;
}
