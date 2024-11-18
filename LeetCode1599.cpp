//
// Created by 陆泽辉 on 2023/3/5.
//

#include "LeetCode1599.h"

int LeetCode1599::minOperationsMaxProfit(vector<int> &customers, int boardingCost, int runningCost) {
    int curr = 0, maxVal = INT_MIN;
    int n = customers.size(), res = -1, delta = 0;
    int i = 0;
    for (; i < n; i++) {
        int count = min(customers[i] + delta, 4);
        curr += boardingCost * count - runningCost;
        if (curr > 0 && curr > maxVal) {
            res = i + 1;
            maxVal = curr;
        }
        delta = max(customers[i] + delta - 4, 0);
    }
    while (delta > 0) {
        int count = min(delta, 4);
        delta -= count;
        curr += boardingCost * count - runningCost;
        if (curr >= 0 && curr > maxVal) {
            res = i + 1;
            maxVal = curr;
        }
        i++;
    }
    return res;
}
