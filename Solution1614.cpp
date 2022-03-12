//
// Created by luzh on 2022/1/7.
//

#include "Solution1614.h"

int Solution1614::maxDepth(string s) {
    int depth = 0;
    int ans = 0;
    int n = s.size();
    for (int i = 0; i < n; i++) {
        char c = s[i];
        if (c == '(') {
            depth++;
        } else if (c == ')') {
            depth--;
        }
        ans = max(ans, depth);
    }
    return ans;
}
