//
// Created by 陆泽辉 on 2023/3/30.
//

#include "LeetCode1637.h"

int LeetCode1637::maxWidthOfVerticalArea(vector<vector<int>> &points) {
    std::sort(points.begin(), points.end(), [](vector<int>& point1, vector<int>& point2) -> bool {
        return point1[0] < point2[0];
    });
    int res = 0;
    for (int i = 1; i < points.size(); i++) {
        res = max(res, points[i][0] - points[i - 1][0]);
    }
    return res;
}
