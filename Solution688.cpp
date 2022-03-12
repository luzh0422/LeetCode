//
// Created by luzh on 2022/2/17.
//

#include "Solution688.h"
#include <vector>

using namespace std;


double Solution688::knightProbability(int n, int k, int row, int column) {
    vector<vector<int>> dirs = {{-1, -2}, {-2, -1}, {-2, 1}, {-1, 2}, {1, -2}, {2, -1}, {2, 1}, {1, 2}};
    vector<vector<vector<double>>> dp(k + 1, vector<vector<double>>(n, vector<double>(n, 0.0)));
    for (int step = 0; step <= k; step++) {
        for (int rowIndex = 0; rowIndex < n; rowIndex++) {
            for (int columnIndex = 0; columnIndex < n; columnIndex++) {
                if (step == 0) {
                    dp[0][rowIndex][columnIndex] = 1.0;
                } else {
                    for (int l = 0; l < 8; l++) {
                        if (rowIndex + dirs[l][0] >= 0 && rowIndex + dirs[l][0] < n && columnIndex + dirs[l][1] >= 0 && columnIndex + dirs[l][1] < n) {
                            dp[step][rowIndex][columnIndex] += 1.0 / 8.0 * dp[step - 1][rowIndex + dirs[l][0]][columnIndex + dirs[l][1]];
                        }
                    }
                }
            }
        }
    }
    return dp[k][row][column];
}
