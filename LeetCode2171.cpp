//
// Created by luzehui on 2024/1/18.
//

#include "LeetCode2171.h"

long long LeetCode2171::minimumRemoval(vector<int> &beans) {
    std::sort(beans.begin(), beans.end());
    int n = beans.size();
    long long currVal = 0, ans = LLONG_MAX, total = 0;
    for (int i = 1; i < n; i++) {
        total += beans[i] - beans[0];
    }
    ans = min(ans, total + currVal);
    currVal += beans[0];
    for (int i = 1; i < n; i++) {
        total -= (long long)(beans[i] - beans[i - 1]) * (long long)(n - i);
        ans = min(ans, total + currVal);
        currVal += beans[i];
        if (currVal > ans) {
            break;
        }
    }
    return ans;
}
