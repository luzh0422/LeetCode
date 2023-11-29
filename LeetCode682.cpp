//
// Created by 陆泽辉 on 2022/3/26.
//

#include "LeetCode682.h"
#include <stack>

int LeetCode682::calPoints(vector<string> &ops) {
    stack<int> stk = {};
    int n = ops.size();
    for (int i = 0; i < n; i++) {
        if (ops[i] == "+") {
            int first = stk.top();
            stk.pop();
            int second = stk.top();
            stk.push(first);
            stk.push(first + second);
        } else if (ops[i] == "D") {
            int first = stk.top();
            stk.push(first * 2);
        } else if (ops[i] == "C") {
            stk.pop();
        } else {
            int num = stoi(ops[i]);
            stk.push(num);
        }
    }
    int ret = 0;
    while (!stk.empty()) {
        ret += stk.top();
        stk.pop();
    }
    return ret;
}
