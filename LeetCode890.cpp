//
// Created by 陆泽辉 on 2022/6/12.
//

#include "LeetCode890.h"
#include <unordered_map>

vector<string> LeetCode890::findAndReplacePattern(vector<string> &words, string pattern) {
    vector<string> ret = {};
    for (auto& word: words) {
        if (word.size() == pattern.size() && match(word, pattern) && match(pattern, word)) {
            ret.push_back(word);
        }
    }
    return ret;
}

bool LeetCode890::match(string &s1, string &s2) {
    unordered_map<char, char> uM;
    int n = s1.size();
    for (int i = 0; i < n; i++) {
        if (uM.count(s1[i])) {
            if (uM[s1[i]] != s2[i]) {
                return false;
            }
        } else {
            uM.insert(unordered_map<char, char>::value_type (s1[i], s2[i]));
        }
    }
    return true;
}
