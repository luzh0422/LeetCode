//
// Created by luzehui on 2024/5/10.
//

#include "LeetCode2960.h"

int LeetCode2960::countTestedDevices(vector<int> &batteryPercentages) {
    int res = 0, n = batteryPercentages.size();
    for (int i = 0; i < n; i++) {
        if (batteryPercentages[i] > 0) {
            res++;
            for (int j = i + 1; j < n; j++) {
                batteryPercentages[j] = max(0, batteryPercentages[j] - 1);
            }
        }
    }
    return res;
}
