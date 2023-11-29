//
// Created by 陆泽辉 on 2023/1/13.
//

#include "LeetCode2287.h"

#include <unordered_map>

int LeetCode2287::rearrangeCharacters(string s, string target) {
    unordered_map<char, int> uS1;
    unordered_map<char, int> uS2;
    for (auto c : target) {
        if (uS1.count(c)) {
            uS1[c]++;
        } else {
            uS1.emplace(c, 1);
        }
    }
    for (auto c : s) {
        if (uS1.count(c)) {
            if (uS2.count(c)) {
                uS2[c]++;
            } else {
                uS2.emplace(c, 1);
            }
        }
    }
    int res = INT_MAX;
    for (auto iter = uS1.begin(); iter != uS1.end(); iter++) {
        if (uS2.count(iter->first)) {
            res = min(res, uS2[iter->first] / iter->second);
        } else {
            res = 0;
            break;
        }
    }
    return res;
}
