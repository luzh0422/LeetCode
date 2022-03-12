//
// Created by luzh on 2021/9/30.
//

#include "Solution223.h"
#include <algorithm>

int Solution223::computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
    int area1 = (ax2 - ax1) * (ay2 - ay1);
    int area2 = (bx2 - bx1) * (by2 - by1);
    // 在x轴没有重叠时；
    if (ax1 < bx1 && ax2 < bx1 || bx1 < ax1 && bx2 < ax1) {
        return area1 + area2;
    }
    // 在y轴没有重叠时；
    if (bx1 < ax1 && bx2 < ax1 || ax1 < bx1 && ax2 < bx1) {
        return area1 + area2;
    }
    int x = std::min(ax2, bx2) - std::max(ax1, bx1);
    int y = std::min(ay2, by2) - std::max(ay1, by1);
    return area1 + area2 - x * y;
}
