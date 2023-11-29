//
// Created by 陆泽辉 on 2023/3/12.
//

#include "LeetCodeMian1705.h"
#include <unordered_map>

vector<string> LeetCodeMian1705::findLongestSubarray(vector<string> &array) {
    int n = array.size(), left = 0, right = 0;
    unordered_map<int, int> uM{{0, 0}};
    vector<pair<int, int>> prefix(n + 1, {0, 0});
    for (int i = 0; i < n; i++) {
        if (array[i][0] >= 'A' && array[i][0] <= 'Z' || array[i][0] >= 'a' && array[i][0] <= 'z') {
            prefix[i + 1].first = prefix[i].first + 1;
            prefix[i + 1].second = prefix[i].second;
        } else {
            prefix[i + 1].first = prefix[i].first;
            prefix[i + 1].second = prefix[i].second + 1;
        }
        int delta = prefix[i + 1].first - prefix[i + 1].second;
        if (uM.count(delta) && i - uM[delta] > right - left) {
            right = i;
            left = uM[delta];
        } else {
            uM.emplace(delta, i + 1);
        }
    }
    if (right - left <= 0) {
        return {};
    }
    vector<string> res;
    auto iter1 = array.begin(), iter2 = array.begin();
    advance(iter1, left);
    advance(iter2, right + 1);
    res.assign(iter1, iter2);
    return res;
}
