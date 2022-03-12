//
// Created by luzh on 2021/9/13.
//

#include "Solution447.h"

#include <unordered_map>

int Solution447::numberOfBoomerangs(vector<vector<int>> &points) {
    int res = 0;
    int n = points.size();
    vector<unordered_map<int, int>> dis(n, {});
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j)
                continue;
            int disX = points[i][0] - points[j][0];
            int disY = points[i][1] - points[j][1];
            int distance = disX * disX + disY * disY;
            if (dis[i].count(distance)) {
                res += 2 * dis[i][distance];
                dis[i][distance] ++;
            } else {
                dis[i][distance] = 1;
            }
        }
    }
    return res;
}
