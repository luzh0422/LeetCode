//
// Created by luzehui on 25-1-6.
//

#include "LeetCode2274.h"

int LeetCode2274::maxConsecutive(int bottom, int top, vector<int> &special) {
    int res = 0, n = special.size();
    if (n == 0) {
        res = top - bottom;
        return res;
    }
    std::sort(special.begin(), special.end());
    res = special[0] - bottom;
    for (int i = 0; i < n - 1; i++) {
        res = max(special[i + 1] - special[i] - 1, res);
    }
    res = max(top - special[n - 1], res);
    return res;
}
