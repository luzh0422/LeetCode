//
// Created by 陆泽辉 on 2022/9/18.
//

#include "LeetCode1624.h"
#include <unordered_map>

int LeetCode1624::maxLengthBetweenEqualCharacters(string s) {
    unordered_map<char, int> positions;
    int ret = -1;
    int n = s.size();
    for (int i = 0; i < n; i++) {
        char c = s[i];
        if (positions.count(c)) {
            ret = max(ret, i - positions[c] - 1);
        } else {
            positions.insert(unordered_map<char, int>::value_type (c, i));
        }
    }
    return ret;
}
