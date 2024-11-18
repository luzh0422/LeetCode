//
// Created by luzehui on 2024/5/22.
//

#include "LeetCode2225.h"
#include <unordered_map>

vector<vector<int>> LeetCode2225::findWinners(vector<vector<int>> &matches) {
    unordered_map<int, int> uM;
    for (auto match : matches) {
        if (!uM.count(match[0])) {
            uM.emplace(match[0], 0);
        }
        if (!uM.count(match[1])) {
            uM.emplace(match[1], 1);
        } else {
            uM[match[1]]++;
        }
    }
    vector<vector<int>> res(2);
    for (auto iter = uM.begin(); iter != uM.end(); iter++) {
        if (iter->second == 0) {
            res[0].push_back(iter->first);
        } else if (iter->second == 1) {
            res[1].push_back(iter->first);
        }
    }
    for (auto& arr : res) {
        std::sort(arr.begin(), arr.end());
    }
    return res;
}
