//
// Created by 陆泽辉 on 2023/6/11.
//

#include "LeetCode1170.h"

vector<int> LeetCode1170::numSmallerByFrequency(vector<string> &queries, vector<string> &words) {
    auto f = [](string& s) -> int {
        auto c = 'z';
        int res = 0;
        for (auto& cc : s) {
            if (cc < c) {
                c = cc;
                res = 1;
            } else if (cc == c) {
                res++;
            }
        }
        return res;
    };
    vector<int> suffix(12, 0);
    for (auto& word : words) {
        suffix[f(word)]++;
    }
    for (int i = 10; i >= 0; i--) {
        suffix[i] += suffix[i + 1];
    }
    vector<int> res;
    for (auto& query : queries) {
        res.push_back(suffix[f(query) + 1]);
    }
    return res;
}
