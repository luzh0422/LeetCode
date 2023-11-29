//
// Created by 陆泽辉 on 2023/3/14.
//

#include "LeetCode1605.h"

vector<vector<int>> LeetCode1605::restoreMatrix(vector<int> &rowSum, vector<int> &colSum) {
    int m = rowSum.size(), n = colSum.size();
    vector<vector<int>> res(m, vector<int>(n, 0));
    for (int i = 0; i < m; i++) {
        res[i][0] = rowSum[i];
    }
    for (int i = 0; i < n - 1; i++) {
        int col = colSum[i], currCol = 0;
        for (int j = 0; j < m; j++) {
            currCol += res[j][i];
            if (currCol > col) {
                res[j][i + 1] = currCol - col;
                res[j][i] = res[j][i] - res[j][i + 1];
                currCol = col;
            }
        }
    }
    return res;
}
