//
// Created by luzehui on 2024/1/4.
//

#include "LeetCode2397.h"

int LeetCode2397::maximumRows(vector<vector<int>> &matrix, int numSelect) {
    int m = matrix.size(), n = matrix[0].size();
    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans = max(ans, maximumRows(matrix, numSelect, i));
    }
    for (int i = 0; i < m; i++) {
        bool tag = true;
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] == 1) {
                tag = false;
                break;
            }
        }
        if (tag) {
            ans += 1;
        }
    }
    return ans;
}

int LeetCode2397::maximumRows(vector<vector<int>> &matrix, int numSelect, int start) {
    if (numSelect == 0) {
        return 0;
    }
    int m = matrix.size(), n = matrix[0].size();
    if (start == n) {
        return 0;
    }
    int ans = 0;
    for (int i = 0; i < m; i++) {
        if (matrix[i][start] == 1) {
            bool tag = true;
            for (int j = 0; j < n; j++) {
                if (j != start && matrix[i][j] == 1) {
                    tag = false;
                }
            }
            if (tag) {
                ans++;
            }
            matrix[i][start] = 2;
        }
    }
    int temp = 0;
    for (int i = start + 1; i < n; i++) {
        temp = max(temp, maximumRows(matrix, numSelect - 1, i));
    }
    for (int i = 0; i < m; i++) {
        if (matrix[i][start] == 2) {
            matrix[i][start] = 1;
        }
    }
    ans += temp;
    return ans;
}
