//
// Created by luzehui on 2024/9/19.
//

#include "LeetCode2414.h"

int LeetCode2414::longestContinuousSubstring(std::string s) {
    int res = 1, curr = 1;
    for (int i = 1; i < s.size(); i++) {
        if (s[i] == s[i - 1] + 1) {
            curr++;
        } else {
            curr = 1;
        }
        res = max(res, curr);
    }
    return res;
}
