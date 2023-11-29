//
// Created by 陆泽辉 on 2023/2/28.
//

#include "LeetCode2363.h"
#include <unordered_map>

vector<vector<int>> LeetCode2363::mergeSimilarItems(vector<vector<int>> &items1, vector<vector<int>> &items2) {
    unordered_map<int, int> uM;
    for (auto &item : items1) {
        if (uM.count(item[0])) {
            uM[item[0]] += item[1];
        } else {
            uM[item[0]] = item[1];
        }
    }
    for (auto &item : items2) {
        if (uM.count(item[0])) {
            uM[item[0]] += item[1];
        } else {
            uM[item[0]] = item[1];
        }
    }
    vector<vector<int>> res;
    for (auto iter = uM.begin(); iter != uM.end(); iter++) {
        res.push_back({iter->first, iter->second});
    }
    std::sort(res.begin(), res.end(), [](vector<int>& r1, vector<int>& r2) -> bool {
        return r1[0] < r2[0];
    });
    return res;
}
