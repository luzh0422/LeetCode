//
// Created by 陆泽辉 on 2022/11/17.
//

#include "LeetCode792.h"
#include <unordered_map>

int LeetCode792::numMatchingSubseq(string s, vector<string> &words) {
    vector<vector<int>> sArr(26, vector<int>{});
    for (int i = 0; i < s.size(); i++) {
        sArr[s[i] - 'a'].push_back(i);
    }
    /**
     * 结果先取全集，当不满足条件的情况下再减少。
     */
    int ret = words.size();
    for (auto& word : words) {
        if (word.size() > s.size()) {
            ret--;
            continue;
        }
        int lastPos = -1;
        for (char c : word) {
            auto& ps = sArr[c - 'a'];
            /**
             * 核心算法在这个二分查找；
             */
            auto it = upper_bound(ps.begin(), ps.end(), lastPos);
            if (it == ps.end()) {
                --ret;
                break;
            }
            lastPos = *it;
        }
    }
    return ret;
}
