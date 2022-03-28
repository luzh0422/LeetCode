//
// Created by luzh on 2022/3/24.
//

#include "LeetCode661.h"

vector<vector<int>> LeetCode661::imageSmoother(vector<vector<int>> &img) {
    int m = img.size();
    int n = img[0].size();
    vector<vector<int>> ret(m, vector<int>(n, 0));
    vector<pair<int, int>> dirs = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            int total = img[i][j];
            int count = 1;
            for (int k = 0; k < 8; k++) {
                int rowStep = dirs[k].first, columnStep = dirs[k].second;
                if (i + rowStep >= 0 && i + rowStep < m && j + columnStep >= 0 && j + columnStep < n) {
                    total += img[i + rowStep][j + columnStep];
                    count++;
                }
            }
            ret[i][j] = total / count;
        }
    }
    return ret;
}
