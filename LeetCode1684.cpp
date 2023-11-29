//
// Created by 陆泽辉 on 2022/11/8.
//

#include "LeetCode1684.h"

int LeetCode1684::countConsistentStrings(string allowed, vector<string> &words) {
    vector<int> chars(26, 0);
    for (auto ch : allowed) {
        chars[ch - 'a'] = 1;
    }
    int ret = 0;
    for (auto word : words) {
        ret++;
        for (auto ch : word) {
            if (chars[ch - 'a'] == 0) {
                ret--;
                break;
            }
        }
    }
    return ret;
}
