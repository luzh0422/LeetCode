//
// Created by 陆泽辉 on 2022/11/1.
//

#include "LeetCode1662.h"

bool LeetCode1662::arrayStringsAreEqual(vector<string> &word1, vector<string> &word2) {
    string s1 = "", s2 = "";
    for (auto word : word1) {
        s1 += word;
    }
    for (auto word : word2) {
        s2 += word;
    }
    return s1 == s2;
}
