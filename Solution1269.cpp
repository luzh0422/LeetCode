//
// Created by luzh on 2021/5/13.
//

#include "Solution1269.h"

#include <vector>

using namespace std;

int Solution1269::numWays(int steps, int arrLen) {
    const int MODULO = 10000000007;
    int maxColumn = min(steps, arrLen - 1);
    vector<vector<int>> dp(steps + 1, vector<int>(maxColumn + 1));
    /**
     * initialize;
     */
    dp[0][0] = 1;
    for (int i = 1; i <= steps; i++) {
        for (int j = 0; j <= maxColumn; j++) {
            /**
             * 走了i - 1步，到达第j个格子的数量，第i步可以选择不走；
             */
            dp[i][j] = dp[i - 1][j];
            /**
             * 考虑格子的边界条件；
             */
            if (j - 1 >= 0) {
                /**
                 * 走了i - 1步，到达了第j - 1个格子的数量，往右走一步，到达第j个格子；
                 */
                dp[i][j] = (dp[i][j] + dp[i - 1][j - 1]) % MODULO;
            }
            if (j + 1 <= maxColumn) {
                /**
                 * 走了i - 1步，到达了第j + 1个格子的数量，往左走一步，到达第j个格子；
                 */
                dp[i][j] = (dp[i][j] + dp[i - 1][j + 1]) % MODULO;
            }
        }
    }
    return dp[0][0];
}
