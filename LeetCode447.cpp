//
// Created by luzehui on 2024/1/8.
//

#include "LeetCode447.h"

int LeetCode447::numberOfBoomerangs(vector<vector<int>> &points) {
    int n = points.size();
    vector<vector<int>> distance(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i != j) {
                int d = pow((points[i][0] - points[j][0]), 2) + pow((points[i][1] - points[j][1]), 2);
                distance[i][j] = d;
            }
        }
    }
    int res = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (i != j) {
                int dIJ = distance[i][j];
                for (int k = j + 1; k < n; k++) {
                    if (i != k && j != k) {
                        int dIK = distance[i][k];
                        if (dIJ == dIK) {
                            res += 2;
                        }
                    }
                }
            }
        }
    }
    return res;
}
