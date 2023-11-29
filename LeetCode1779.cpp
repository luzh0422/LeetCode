//
// Created by 陆泽辉 on 2022/12/1.
//

#include "LeetCode1779.h"

int LeetCode1779::nearestValidPoint(int x, int y, vector<vector<int>> &points) {
    int n = points.size();
    int MAX_DISTANCE = 0x3f3f3f3f;
    int ret = -1;
    for (int i = 0; i < n; i++) {
        auto point = points[i];
        if (point[0] == x || point[1] == y) {
            int curr = abs(point[0] - x) + abs(point[1] - y);
            if (curr < MAX_DISTANCE) {
                ret = i;
            }
        }
    }
    return ret;
}
