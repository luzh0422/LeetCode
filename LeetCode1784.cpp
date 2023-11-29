//
// Created by 陆泽辉 on 2022/10/3.
//

#include "LeetCode1784.h"

bool LeetCode1784::checkOnesSegment(string s) {
    bool hasOne = false, countOne = false;
    int n = s.size();
    for (int i = 0; i < n; i++) {
        if (s[i] == '1') {
            if (i > 0 && s[i - 1] == '1') {
                continue;
            } else {
                if (!hasOne) {
                    hasOne = true;
                    countOne = true;
                } else {
                    countOne = false;
                }
            }
        }
    }
    return hasOne & countOne;
}
