//
// Created by luzehui on 25-3-23.
//

#include "LeetCode2116.h"
#include <stack>

bool LeetCode2116::canBeValid(std::string s, std::string locked) {
    stack<int> st1, st2;
    int n = locked.size();
    for (int i = 0; i < n; i++) {
        if (locked[i] == '0') {
            st1.push(i);
        } else if (s[i] == '(') {
            st2.push(i);
        } else {
            if (!st2.empty()) {
                st2.pop();
            } else if (!st1.empty()) {
                st1.pop();
            } else {
                return false;
            }
        }
    }
    while (!st1.empty() && !st2.empty()) {
        if (st1.top() < st2.top()) {
            return false;
        }
        st1.pop();
        st2.pop();
    }
    if (!st2.empty()) {
        return false;
    }
    if (!st1.empty()) {
        return st1.size() % 2 == 0;
    }
    return true;
}
