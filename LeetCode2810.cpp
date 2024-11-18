//
// Created by luzehui on 2024/4/1.
//

#include "LeetCode2810.h"

string LeetCode2810::finalString(std::string s) {
    string res = "";
    int n = s.size();
    for (int i = 0; i < n; i++) {
        if (s[i] == 'i') {
            reverse(res.begin(), res.end());
        } else {
            res += s[i];
        }
    }
    return res;
}
