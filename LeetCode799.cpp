//
// Created by 陆泽辉 on 2022/11/20.
//

#include "LeetCode799.h"

#include <vector>

using namespace std;

/**
 * 模拟 + 动态规划；
 * @param poured
 * @param query_row
 * @param query_glass
 * @return
 */
double LeetCode799::champagneTower(int poured, int query_row, int query_glass) {
    vector<vector<double>> dp(101, vector<double>(101, 0.0f));
    /**
     * 所有的酒都装入第一个杯子；
     */
    dp[0][0] = poured;
    for (int i = 0; i <= query_row; i++) {
        for (int j = 0; j <= i; j++) {
            /**
             * 如果这个杯子可以装满；
             */
            if (dp[i][j] >= 1) {
                /**
                 * 装满这个杯子后剩余的酒；
                 */
                double remained = dp[i][j] - 1;
                dp[i][j] = 1;

                /**
                 * 它下面的两个杯子分取剩余的酒；
                 */
                dp[i + 1][j] += remained / 2;
                dp[i + 1][j + 1] += remained / 2;
            }
        }
    }
    return  dp[query_row][query_glass];
}
