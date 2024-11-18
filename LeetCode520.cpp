//
// Created by luzehui on 2024/6/23.
//

#include "LeetCode520.h"
#include <algorithm>

bool LeetCode520::detectCapitalUse(std::string word) {
    if (word[0] >= 'A' && word[0] <= 'Z') {
        if (word.size() == 1) {
            return true;
        } else if (word.size() > 1 && (all_of(word.begin() + 1, word.end(), [](char c) -> bool {
            return c >= 'A' && c <= 'Z';
        }) || all_of(word.begin() + 1, word.end(), [](char c) -> bool {
            return c >= 'a' && c <= 'z';
        }))) {
            return true;
        }
    } else if (word[0] >= 'a' && word[0] <= 'z' && all_of(word.begin(), word.end(), [](char c) -> bool {
        return c >= 'a' && c <= 'z';
    })) {
        return true;
    }
    return false;
}
