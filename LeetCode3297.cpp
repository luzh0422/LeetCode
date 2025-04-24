//
// Created by luzehui on 25-1-9.
//

#include "LeetCode3297.h"
#include <vector>
#include <iostream>

long long LeetCode3297::validSubstringCount(std::string word1, std::string word2) {
    vector<int> diff(26, 0);
    for (auto &c: word2) {
        diff[c - 'a']++;
    }
    int n = word1.size();
    int l = 0, r = 1;
    long long res = 0;
    diff[word1[r - 1] - 'a']--;
    while (l <= r && r <= n) {
        if (all_of(diff.begin(), diff.end(),
                   [&](int num) -> bool {
                       return num <= 0;
                   })) {
            res += n - r + 1;
            diff[word1[l] - 'a']++;
            l++;
        } else {
            r++;
            if (r <= n)
                diff[word1[r - 1] - 'a']--;
        }
    }
    return res;
}
