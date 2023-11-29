//
// Created by 陆泽辉 on 2022/5/28.
//

#include "LeetCode1021.h"
#include <stack>

string LeetCode1021::removeOuterParentheses(string s) {
    int n = s.size();
    int count = 0;
    stack<int> stk;
    string ret = "";
    for (int i = 0; i < n; i++) {
        if (s[i] == '(') {
            stk.push(i);
            ret += "(";
        } else if (s[i] == ')') {
            if (stk.size() == 1) {
                int pos = stk.top();
                stk.pop();
                pos -= count * 2;
                count++;
                ret.erase(pos, 1);
            } else {
                stk.pop();
                ret += ')';
            }
        } else {
            ret += s[i];
        }
    }
    return ret;
}
