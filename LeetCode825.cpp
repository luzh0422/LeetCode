//
// Created by luzehui on 2024/11/17.
//

#include "LeetCode825.h"

int LeetCode825::numFriendRequests(vector<int> &ages) {
    // 对于每个x，y需要满足：
    // 0.5 * x + 7 < y <= x;
    // x就会给y发消息；
    std::sort(ages.begin(), ages.end());
    int n = ages.size(), res = 0;
    int left = 0, right = 0;
    for (int i = 0; i < n; i++) {
        int curr = ages[i];
        if (curr <= 14) {
            continue;
        }
        while (left < n && ages[left] <= 0.5 * curr + 7) {
            left++;
        }
        while (right < n && ages[right] <= curr) {
            right++;
        }
        res += right - left - 1;
    }
    return res;
}
