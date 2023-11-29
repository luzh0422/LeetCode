//
// Created by 陆泽辉 on 2023/4/29.
//

#include "LeetCode2423.h"
#include <vector>
#include <unordered_set>

bool LeetCode2423::equalFrequency(string word) {
    vector<int> counts(26, 0);
    for (auto c : word) {
        counts[c - 'a']++;
    }
    for (int i = 0; i < 26; i++) {
        if (counts[i] == 0) {
            continue;
        }
        counts[i]--;
        unordered_set<int> uS;
        for (auto c : counts) {
            if (c > 0) {
                uS.insert(c);
            }
        }
        if (uS.size() == 1) {
            return true;
        }
    }
    return false;
}
