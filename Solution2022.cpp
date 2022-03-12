//
// Created by luzh on 2022/1/1.
//

#include "Solution2022.h"

vector<vector<int>> Solution2022::construct2DArray(vector<int> &original, int m, int n) {
    int size = original.size();
    if (size != m * n) {
        return {};
    }
    vector<vector<int>> ans(m, vector<int>(n, 0));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            ans[i][j] = original[i * n + j];
        }
    }
    return ans;
}
