//
// Created by luzehui on 2023/12/1.
//

#include "LeetCode2661.h"

int LeetCode2661::firstCompleteIndex(vector<int> &arr, vector<vector<int>> &mat) {
    int m = mat.size(), n = mat[0].size();
    vector<int> row(m, 0), column(n, 0);
    vector<pair<int, int>> dict(m * n, pair<int, int>{});
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            dict[mat[i][j] - 1] = {i, j};
        }
    }
    for (int i = 0; i < m * n; i++) {
        int num = arr[i] - 1;
        int r = dict[num].first;
        int c = dict[num].second;
        row[r]++;
        column[c]++;
        if (row[r] == n || column[c] == m) {
            return i;
        }
    }
    return -1;
}
