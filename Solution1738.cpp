//
// Created by luzh on 2021/5/19.
//

#include "Solution1738.h"

int Solution1738::kthLargestValue(vector<vector<int>> &matrix, int k) {
    int row = matrix.size();
    vector<int> ans = {};
    if (row == 0) {
        return 0;
    }
    int column = matrix[0].size();
    vector<vector<int>> preXOR(row, vector<int>(column));
    /**
     * initialize
     */
    preXOR[0][0] = matrix[0][0];
    ans.push_back(preXOR[0][0]);
    for (int i = 1; i < column; i++) {
        preXOR[0][i] = preXOR[0][i - 1] ^ matrix[0][i];
        ans.push_back(preXOR[0][i]);
    }
    for (int i = 1; i < row; i++) {
        preXOR[i][0] = preXOR[i - 1][0] ^ matrix[i][0];
        ans.push_back(preXOR[i][0]);
    }
    for (int i = 1; i < row; i++) {
        for (int j = 1; j < column; j++) {
            preXOR[i][j] = preXOR[i - 1][j] ^ preXOR[i][j - 1] ^ preXOR[i - 1][j - 1] ^ matrix[i][j];
            ans.push_back(preXOR[i][j]);
        }
    }
    sort(ans.begin(), ans.end(), [](int num1, int num2) -> bool {
        return num1 < num2;
    });
    return ans[k - 1];
}
