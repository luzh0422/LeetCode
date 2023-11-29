//
// Created by 陆泽辉 on 2022/8/12.
//

#include "LeetCode1282.h"

#include <unordered_map>

vector<vector<int>> LeetCode1282::groupThePeople(vector<int> &groupSizes) {
    unordered_map<int, vector<int>> uM;
    vector<vector<int>> ret = {};
    int n = groupSizes.size();
    for (int i = 0; i < n; i++) {
        int groupSize = groupSizes[i];
        if (uM.count(groupSize)) {
            if (uM[groupSize].size() == groupSize) {
                ret.push_back(uM[groupSize]);
                uM[groupSize].clear();
            }
            uM[groupSize].emplace_back(i);
        } else {
            uM.insert(unordered_map<int, vector<int>>::value_type (groupSize, {i}));
        }
    }
    for (auto it = uM.begin(); it != uM.end(); it++) {
        if (it->second.size() != 0) {
            ret.push_back(it->second);
        }
    }
    return ret;
}
