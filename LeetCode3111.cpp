//
// Created by luzehui on 2024/7/31.
//

#include "LeetCode3111.h"

int LeetCode3111::minRectanglesToCoverPoints(vector<vector<int>> &points, int w) {
    std::sort(points.begin(), points.end(), [](const vector<int>& point1, const vector<int>& point2) -> bool {
        return point1[0] < point2[0];
    });
    auto curr = points[0];
    int res = 0;
    for (int i = 1; i < points.size(); i++) {
        if (points[i][0] - curr[0] > w) {
            res++;
            curr = points[i];
        }
    }
    return res;
}
