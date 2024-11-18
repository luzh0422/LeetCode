//
// Created by luzehui on 2024/6/6.
//

#include "LeetCode2938.h"

long long LeetCode2938::minimumSteps(std::string s) {
    int n = s.size();
    long long res = 0ll, count = 0ll;
    for (int i = 0; i < n; i++) {
        if (s[i] == '0') {
            res += count;
        } else {
            count++;
        }
    }
    return res;
}
