//
// Created by 陆泽辉 on 2022/10/9.
//

#include "LeetCode865.h"
#include <stack>
#include <numeric>

int LeetCode865::scoreOfParentheses(string s) {
   int n = s.size();
   stack<int> stk;
   int ret = 0;
   for (int i = 0; i < n; i++) {
       if (s[i] == '(') {
           if (stk.empty()) {
               stk.push(1);
           } else {
               stk.top() = 0;
               stk.push(pow(2, stk.size()));
           }
       } else if (s[i] == ')') {
           ret += stk.top();
           stk.pop();
       }
   }
   return ret;
}
