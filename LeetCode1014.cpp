//
// Created by luzehui on 2024/9/23.
//

#include "LeetCode1014.h"

int LeetCode1014::maxScoreSightseeingPair(vector<int> &values) {
    int maxValue1 = values[0], res = 0;
    for (int i = 1; i < values.size(); i++) {
        int curr = maxValue1 + values[i] - i;
        res = max(curr, res);
        maxValue1 = max(maxValue1, values[i] + i);
    }
    return res;
}
