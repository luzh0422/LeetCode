//
// Created by 陆泽辉 on 2023/1/8.
//

#include "LeetCode2185.h"

int LeetCode2185::prefixCount(vector<string> &words, string pref) {
    int res = 0;
    for (auto& word : words) {
        if (word.find(pref) == 0) {
            res++;
        }
    }
    return res;
}
