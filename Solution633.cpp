//
// Created by luzh on 2021/4/28.
//

#include "Solution633.h"

#include <math.h>

bool Solution633::judgeSquareSum(int c) {
    int left = 0;
    int right = (int)sqrt(c);
    while (left <= right) {
        if (pow(left, 2) + pow(right, 2) == c) {
            return true;
        } else if (pow(left, 2) + pow(right, 2) > c) {
            right--;
        } else {
            left++;
        }
    }
    return false;
}
