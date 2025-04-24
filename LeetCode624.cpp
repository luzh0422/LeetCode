//
// Created by luzehui on 25-2-19.
//

#include "LeetCode624.h"

int LeetCode624::maxDistance(vector<vector<int>> &arrays) {
    int minVal = arrays[0].front();
    int maxVal = arrays[0].back();
    int res = 0;
    for (int i = 1; i < arrays.size(); i++) {
        int currMinVal = arrays[i].front();
        int currMaxVal = arrays[i].back();
        res = max(res, abs(currMaxVal - minVal));
        res = max(res, abs(currMinVal - maxVal));
        minVal = min(minVal, currMinVal);
        maxVal = max(maxVal, currMaxVal);
    }
    return res;
}
