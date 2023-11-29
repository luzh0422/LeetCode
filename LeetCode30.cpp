//
// Created by 陆泽辉 on 2022/6/23.
//

#include "LeetCode30.h"
#include <unordered_map>

vector<int> LeetCode30::findSubstring(string s, vector<string> &words) {
    vector<int> res;
    int m = words.size(), n = words[0].size(), ls = s.size();
    unordered_map<string, int> wordCnt;
    for (string &word: words) {
        ++wordCnt[word];
    }
    for (int i = 0; i + m * n <= ls; ++i) {
        unordered_map<string, int> strCnt;
        int j = 0;
        for (; j < m; ++j) {
            string t = s.substr(i + j * n, n);
            if (!wordCnt.count(t))
                break;
            ++strCnt[t];
            if (strCnt[t] > wordCnt[t])
                break;
        }
        if (j == m) res.emplace_back(i);
    }
    return res;
}
