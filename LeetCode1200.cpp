//
// Created by 陆泽辉 on 2022/7/4.
//

#include "LeetCode1200.h"
#include <map>

vector<vector<int>> LeetCode1200::minimumAbsDifference(vector<int> &arr) {
    std::sort(arr.begin(), arr.end());
    map<int, vector<vector<int>>> m;
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        int diff = arr[i + 1] - arr[i];
        if (m.count(diff)) {
            m[diff].emplace_back(arr[i], arr[i + 1]);
        } else {
            m.insert(map<int, vector<vector<int>>>::value_type(diff, {{arr[i], arr[i] + 1}}));
        }
    }
    auto ret = m.begin()->second;
    return ret;
}
