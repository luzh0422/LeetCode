//
// Created by 陆泽辉 on 2022/6/8.
//

#include "LeetCode1037.h"

bool LeetCode1037::isBoomerang(vector<vector<int>> &points) {
    auto point1 = points[0], point2 = points[1], point3 = points[2];
    /**
     * 存在相同的点；
     */
    if (point1[0] == point2[0] && point1[1] == point2[1] || point1[0] == point3[0] && point1[1] == point3[1] || point2[0] == point3[0] && point2[1] == point3[1]) {
        return false;
    } else if (point1[0] == point2[0] && point1[0] == point3[0]) {
        return false;
    } else if (point1[0] == point2[0] && point1[0] != point3[0] || point1[0] == point3[0] && point1[0] != point2[0]) {
        return true;
    } else {
        double delta1 = double(point1[1] - point2[1]) / double(point1[0] - point2[0]);
        double delta2 = double(point1[1] - point3[1]) / double(point1[0] - point3[0]);
        if (delta1 == delta2) {
            return false;
        } else {
            return true;
        }
    }
}
