//
// Created by luzh on 2021/6/10.
//

#include "Solution485.h"

int Solution485::change(int amount, vector<int> &coins) {
    int size = coins.size();
    /**
     * dp[i][j] 代表前i种面额，兑换总金额j，总共有多少种方案；
     */
    vector<vector<int>> dp(size + 1, vector<int>(amount + 1, INT_MIN));
    /**
     * initialize
     */
    dp[0][0] = 1;
    for (int i = 1; i <= amount; i++) {
        dp[0][i] = 0;
    }
    for (int i = 1; i <= size; i++) {
        int coin = coins[i];
        for (int j = 1; j <= amount; j++) {
            if (coin > j) {
                /**
                 * 当前的面额大于总金额；
                 */
                dp[i][j] = dp[i - 1][j];
            } else {
                /**
                 * 当前的面额可以构建总金额；
                 */
                 int index = 0;
                 int count = 0;
                 while (index * coin <= j) {
                    count += dp[i - 1][j - index * coin];
                    index++;
                 }
                 dp[i][j] = count;
            }
        }
    }
    return dp[size][amount];
}
