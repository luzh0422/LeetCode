//
// Created by 陆泽辉 on 2022/11/9.
//

#include "LeetCode764.h"

int LeetCode764::orderOfLargestPlusSign(int n, vector<vector<int>> &mines) {
    vector<vector<int>> matrix(n, vector<int>(n, 1));
    for (auto mine : mines) {
        int left = mine[0];
        int right = mine[1];
        matrix[left][right] = 0;
    }
    vector<vector<vector<int>>> counts(n, vector<vector<int>>(n, vector<int>(4, 0)));
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < n; j++) {
            /**
             * 列优先遍历，从左到右；
             */
            if (matrix[i][j - 1] == 0) {
                counts[i][j][0] = 0;
            } else {
                counts[i][j][0] = counts[i][j - 1][0] + 1;
            }
            /**
             * 行优先遍历，从上到下；
             */
            if (matrix[j - 1][i] == 0) {
                counts[j][i][2] = 0;
            } else {
                counts[j][i][2] = counts[j - 1][i][2] + 1;
            }
        }
        for (int j = n - 2; j >= 0; j--) {
            /**
             * 列优先遍历，从右刀左；
             */
            if (matrix[i][j + 1] == 0) {
                counts[i][j][1] = 0;
            } else {
                counts[i][j][1] = counts[i][j + 1][1] + 1;
            }
            /**
             * 行优先遍历，从下到上
             */
            if (matrix[j + 1][i] == 0) {
                counts[j][i][3] = 0;
            } else {
                counts[j][i][3] = counts[j + 1][i][3] + 1;
            }
        }
    }
    int ret = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] == 1) {
                ret = max(ret, min(min(min(counts[i][j][0], counts[i][j][1]), counts[i][j][2]), counts[i][j][3]) + 1);
            }
        }
    }
    return ret;
}
