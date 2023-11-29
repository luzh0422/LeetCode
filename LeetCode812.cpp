//
// Created by 陆泽辉 on 2022/5/15.
//

#include "LeetCode812.h"

double LeetCode812::largestTriangleArea(vector<vector<int>> &points) {
    double maxArea = 0;
    int n = points.size();
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            for (int k = j + 1; k < n; k++) {
                vector<int> point1 = points[i], point2 = points[j], point3 = points[k];
                double area = triangleArea(point1, point2, point3);
                maxArea = max(maxArea, area);
            }
        }
    }
    return maxArea;
}

/**
 * triangleArea = 1 / 2 * |x1, y1, 1,|
 *                        |x2, y2, 1,|
 *                        |x3, y3, 1 |;
 * @param point1
 * @param point2
 * @param point3
 * @return
 */
double LeetCode812::triangleArea(vector<int> &point1, vector<int> &point2, vector<int> &point3) {
    double x1 = double(point1[0]), y1 = double(point1[1]),
           x2 = double(point2[0]), y2 = double(point2[1]),
           x3 = double(point3[0]), y3 = double(point3[1]);
    double temp = x1 * y2 + x2 * y3 + x3 * y1 - x3 * y2 - x1 * y3 - x2 * y1;
    return double(1 / 2) * temp;
}
