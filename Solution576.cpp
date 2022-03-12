//
// Created by luzh on 2021/8/15.
//

#include "Solution576.h"

int Solution576::findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
    vector<vector<int>> matrix(m, vector<int>(n));
    for (int i = 0; i < n; i++) {
        matrix[0][i] += 1;
        matrix[m - 1][i] += 1;
    }
    for (int i = 0; i < m; i++) {
        matrix[i][0] += 1;
        matrix[i][n - 1] += 1;
    }
    return findPaths(matrix, m, n, maxMove, startRow, startColumn);
}

int Solution576::findPaths(vector<vector<int>> &matrix, int m, int n, int maxMove, int currRow, int currColumn) {
    if (currRow < 0 || currColumn < 0 || currRow >= m || currColumn >= n || maxMove <= 0) {
        return 0;
    }
    const int mod = 100000007;
    int ans = matrix[currRow][currColumn] + findPaths(matrix, m, n, maxMove - 1, currRow - 1, currColumn) + findPaths(matrix, m, n, maxMove - 1, currRow, currColumn - 1) + findPaths(matrix, m, n, maxMove - 1, currRow + 1, currColumn) + findPaths(matrix, m, n, maxMove - 1, currRow, currColumn + 1);
    return ans;
}
