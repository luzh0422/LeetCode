//
// Created by luzehui on 2024/10/15.
//

#include "LeetCode3200.h"
#include <algorithm>

int LeetCode3200::maxHeightOfTriangle(int red, int blue) {
    int redFirst = maxHeight(red, blue);
    int blueFirst = maxHeight(blue, red);
    return std::max(redFirst, blueFirst);
}

int LeetCode3200::maxHeight(int first, int second) {
    int index = 0, curr = 1, res = 0;
    while (1) {
        if (index == 0) {
            if (first >= curr) {
                res++;
                first -= curr;
            } else {
                break;
            }
        } else {
            if (second >= curr) {
                res++;
                second -= curr;
            } else {
                break;
            }
        }
        index ^= 1;
        curr++;
    }
    return res;
}
