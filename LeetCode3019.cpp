//
// Created by luzehui on 25-1-7.
//

#include "LeetCode3019.h"

int LeetCode3019::countKeyChanges(std::string s) {
    if (s.size() == 0) {
        return 0;
    }
    int res = 0, curr = 0;
    if (s[0] >= 'a' && s[0] <= 'z') {
        curr = s[0] - 'a';
    } else {
        curr = s[0] - 'A';
    }
    for (int i = 1; i < s.size(); i++) {
        if (curr != s[i] - 'a' && curr != s[i] - 'A') {
            res++;
            if (s[i] >= 'a' && s[i] <= 'z') {
                curr = s[i] - 'a';
            } else {
                curr = s[i] - 'A';
            }
        }
    }
    return res;
}
