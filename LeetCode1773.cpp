//
// Created by 陆泽辉 on 2022/10/29.
//

#include "LeetCode1773.h"
#include <unordered_map>

int LeetCode1773::countMatches(vector<vector<string>> &items, string ruleKey, string ruleValue) {
    unordered_map<string, int> keyToIndex = {
        {"type", 0},
        {"color", 1},
        {"name", 2}
    };
    int ruleIndex = keyToIndex[ruleKey];
    int ret = 0;
    for (auto& item : items) {
        if (item[ruleIndex] == ruleValue) {
            ret++;
        }
    }
    return ret;
}
