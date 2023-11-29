//
// Created by 陆泽辉 on 2022/6/5.
//

#include "LeetCode478.h"
#include <math.h>

/**
 * 根据圆心和半径，找到生成随机数的范围；
 * 然后在这个范围内生成浮点数随机数；
 * 然后判断随机数到圆心的距离是否小于等于半径；如果是，就将随机数加入结果中；如果不是，就重新生成随机数；
 * @param radius
 * @param x_center
 * @param y_center
 */
LeetCode478::LeetCode478(double radius, double x_center, double y_center) {
    left = x_center - radius;
    right = x_center + radius;
    bottom = y_center - radius;
    top = y_center + radius;
    xCenter = x_center;
    yCenter = y_center;
    r = pow(radius, 2.0);
}

vector<double> LeetCode478::randPoint() {
    double x = random() / double(RAND_MAX) * double(right - left) + left;
    double y = random() / double(RAND_MAX) * double(top - bottom) + bottom;
    double distance = pow(x - xCenter, 2.0) + pow(y - yCenter, 2.0);
    while (distance > r) {
        x = random() / double(RAND_MAX) * double(right - left) + left;
        y = random() / double(RAND_MAX) * double(top - bottom) + bottom;
        distance = pow(x - xCenter, 2.0) + pow(y - yCenter, 2.0);
    }
    return {x, y};
}
