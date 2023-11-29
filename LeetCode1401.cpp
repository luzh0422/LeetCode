//
// Created by 陆泽辉 on 2023/6/25.
//

#include <functional>
#include "LeetCode1401.h"

/**
 * 若一个点在圆内，则（x - xCenter) ^ 2 + (y - yCenter) ^ 2 <= radius ^ 2;
 * 同时这个点在矩形内，则 x1 <= x <= x2, y1 <= y <= y2;
 * 若 x1 > center 则 x = x1, 若x2 < center 则x = x2，若x1 <= center <= x2, 则x = center；
 * @param radius
 * @param xCenter
 * @param yCenter
 * @param x1
 * @param y1
 * @param x2
 * @param y2
 * @return
 */
bool LeetCode1401::checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
    /**
     * 求矩形中的点距离圆心的最小距离；
     */
    std::function<int(int, int, int)> helper = [](int num1, int num2, int target) -> int {
        if (num1 > target) {
            return num1;
        } else if (num2 < target) {
            return num2;
        } else {
            return target;
        }
    };
    int pointX = helper(x1, x2, xCenter);
    int pointY = helper(y1, y2, yCenter);
    return (pointX - xCenter) * (pointX - xCenter) + (pointY - yCenter) * (pointY - yCenter) <= radius * radius;
}
