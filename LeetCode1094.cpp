//
// Created by luzehui on 2023/12/6.
//

#include "LeetCode1094.h"

bool LeetCode1094::carPooling(vector<vector<int>> &trips, int capacity) {
    int to_max = 0;
    for (auto& trip : trips) {
        to_max = max(to_max, trip[2]);
    }
    vector<int> diff(to_max + 1);
    for (auto& trip : trips) {
        diff[trip[1]] += trip[0];
        diff[trip[2]] -= trip[0];
    }
    int need = 0;
    for (int i = 0; i <= to_max; i++) {
        need += diff[i];
        if (need > capacity) {
            return false;
        }
    }
    return true;
}
