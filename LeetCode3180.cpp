//
// Created by luzehui on 2024/10/25.
//

#include "LeetCode3180.h"

int LeetCode3180::maxTotalReward(vector<int> &rewardValues) {
    std::sort(rewardValues.begin(), rewardValues.end());
    /**
     * rewardValues的最大值是2000，获取的奖励最多是4000；
     */
    vector<bool> dp(4001, false);
    dp[0] = true;
    int n = rewardValues.size();
    for (int i = 0; i < n; i++) {
        int x = rewardValues[i];
        /**
         * 对于奖励值j，判断j是否为true或者j - x是否为true；
         * 如果为true，则奖励值j可以获取；
         */
        for (int j = x; j < 2 * x; j++) {
            dp[j] = dp[j] || dp[j - x];
        }
    }
    int index = rewardValues.back() * 2;
    while (index >= 0) {
        if (dp[index]) {
            return index;
        }
        index--;
    }
    return 0;
}
