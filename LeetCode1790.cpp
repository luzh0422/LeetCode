//
// Created by 陆泽辉 on 2022/10/11.
//

#include "LeetCode1790.h"
#include <vector>

bool LeetCode1790::areAlmostEqual(string s1, string s2) {
    vector<int> diffs;
    int n = s1.size();
    for (int i = 0; i < n; i++) {
        if (s1[i] != s2[i]) {
            diffs.push_back(i);
        }
        if (diffs.size() > 2) {
            return false;
        }
    }
    if (diffs.size() == 0 || diffs.size() == 2 && s1[diffs[0]] == s2[diffs[1]] && s1[diffs[1]] == s2[diffs[0]]) {
        return true;
    }
    return false;
}
