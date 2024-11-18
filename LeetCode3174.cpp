//
// Created by luzehui on 2024/9/10.
//

#include "LeetCode3174.h"

string LeetCode3174::clearDigits(std::string s) {
    string res = "";
    int n = s.size();
    for (int i = 0; i < n; i++) {
        if (s[i] >= '0' && s[i] <= '9') {
            res.pop_back();
        } else {
            res += s[i];
        }
    }
    return res;
}
