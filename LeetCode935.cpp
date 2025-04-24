//
// Created by luzehui on 24-12-10.
//

#include "LeetCode935.h"
#include <vector>

using namespace std;

int LeetCode935::knightDialer(int n) {
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(4, vector<int>(3, 0)));
    const int MOD = 1e9 + 7;
    vector<vector<int>> dirs = {{-1, -2}, {-2, -1}, {-2, 1}, {-1, 2}, {1, -2}, {2, -1}, {2, 1}, {1, 2}};
    for (int step = 0; step < n; step++) {
        for (int rowIndex = 0; rowIndex < 4; rowIndex++) {
            for (int columnIndex = 0; columnIndex < 3; columnIndex++) {
                if (rowIndex == 3 && (columnIndex == 0 || columnIndex == 2)) {
                    continue;
                }
                if (step == 0) {
                    dp[0][rowIndex][columnIndex] = 1;
                } else {
                    for (int l = 0; l < 8; l++) {
                        if (rowIndex + dirs[l][0] >= 0 && rowIndex + dirs[l][0] < 4 && columnIndex + dirs[l][1] >= 0 && columnIndex + dirs[l][1] < 3) {
                            dp[step][rowIndex][columnIndex] += dp[step - 1][rowIndex + dirs[l][0]][columnIndex + dirs[l][1]];
                            dp[step][rowIndex][columnIndex] %= MOD;
                        }
                    }
                }
            }
        }
    }
    int res = 0;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 3; j++) {
            res += dp[n - 1][i][j];
            res %= MOD;
        }
    }
    return res;
}
