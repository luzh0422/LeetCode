//
// Created by 陆泽辉 on 2023/5/23.
//

#include "LeetCode1090.h"
#include <unordered_map>

int LeetCode1090::largestValsFromLabels(vector<int> &values, vector<int> &labels, int numWanted, int useLimit) {
    vector<pair<int, int>> valuesAndLabels = {};
    int n = values.size();
    for (int i = 0; i < n; i++) {
        valuesAndLabels.emplace_back(values[i], labels[i]);
    }
    std::sort(valuesAndLabels.begin(), valuesAndLabels.end(), [](pair<int, int>& p1, pair<int, int>& p2) -> bool {
        return p1.first > p2.first;
    });
    unordered_map<int, int> cache = {};
    int index = 0;
    int res = 0;
    for (int i = 0; i < n && index < numWanted; i++) {
        if (cache.count(valuesAndLabels[i].second) && cache[valuesAndLabels[i].second] >= useLimit) {
            continue;
        }
        res += valuesAndLabels[i].first;
        index++;
        cache[valuesAndLabels[i].second]++;
    }
    return res;
}
