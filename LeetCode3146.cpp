//
// Created by luzehui on 2024/8/24.
//

#include "LeetCode3146.h"
#include <vector>

int LeetCode3146::findPermutationDifference(std::string s, std::string t) {
    vector<int> sIndex(26, -1);
    for (int i = 0; i < s.size(); i++) {
        sIndex[s[i] - 'a'] = i;
    }
    int res = 0;
    for (int i = 0; i < t.size(); i++) {
        res += abs(sIndex[t[i] - 'a'] - i);
    }
    return res;
}
