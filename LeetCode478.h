//
// Created by 陆泽辉 on 2022/6/5.
//

#ifndef LEETCODE_LEETCODE478_H
#define LEETCODE_LEETCODE478_H

#include <vector>

using namespace std;

class LeetCode478 {
public:
    LeetCode478(double radius, double x_center, double y_center);
    vector<double> randPoint();

private:
    double left, right, bottom, top;
    double xCenter, yCenter, r;
};

#endif //LEETCODE_LEETCODE478_H
