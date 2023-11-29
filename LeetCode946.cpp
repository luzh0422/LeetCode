//
// Created by 陆泽辉 on 2022/8/31.
//

#include "LeetCode946.h"
#include <stack>

bool LeetCode946::validateStackSequences(vector<int> &pushed, vector<int> &popped) {
    int pushedIndex = 0, poppedIndex = 0;
    stack<int> stk = {};
    int n = pushed.size();
    while (pushedIndex < n) {
        stk.push(pushed[pushedIndex]);
        pushedIndex++;
        while (!stk.empty()) {
            auto curr = stk.top();
            if (curr == popped[poppedIndex]) {
                poppedIndex++;
                stk.pop();
            } else {
                break;
            }
        }
    }
    while (!stk.empty()) {
        auto curr = stk.top();
        stk.pop();
        if (curr != popped[poppedIndex]) {
            return false;
        } else {
            poppedIndex++;
        }
    }
    return true;
}
