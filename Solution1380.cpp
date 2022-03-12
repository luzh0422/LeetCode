//
// Created by luzh on 2022/2/15.
//

#include "Solution1380.h"

vector<int> Solution1380::luckyNumbers(vector<vector<int>> &matrix) {
    vector<int> ans = {};
    int m = matrix.size();
    int n = matrix[0].size();
    for (int i = 0; i < m; i++) {
        int column = 0;
        for (int j = 1; j < n; j++) {
            if (matrix[i][j] < matrix[i][column]) {
                column = j;
            }
        }
        bool check = true;
        for (int j = 0; j < m; j++) {
            if (j != i && matrix[j][column] > matrix[i][column]) {
                check = false;
            }
        }
        if (check) {
            ans.push_back(matrix[i][column]);
        }
    }
    return ans;
}
