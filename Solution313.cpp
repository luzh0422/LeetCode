//
// Created by luzh on 2021/8/9.
//

#include "Solution313.h"

int Solution313::nthSuperUglyNumber(int n, vector<int> &primes) {
    vector<int> dp(n + 1);
    dp[1] = 1;
    int m = primes.size();
    vector<int> pointers(m, 1);
    for (int i = 2; i <= n; i++) {
        vector<int> nums(m);
        int minNum = INT_MAX;
        for (int j = 0; j < m; j++) {
            nums[j] = dp[pointers[j]] * primes[j];
            minNum = min(minNum, nums[j]);
        }
        dp[i] = minNum;
        for (int j = 0; j < m; j++) {
            /**
             * 避免在dp中加入重复的元素；
             */
            if (minNum == nums[j]) {
                pointers[j]++;
            }
        }
    }
    return dp[n];
}
