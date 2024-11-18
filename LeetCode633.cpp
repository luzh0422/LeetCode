//
// Created by luzehui on 2024/11/4.
//

#include "LeetCode633.h"
#include <cmath>

using namespace std;

bool LeetCode633::judgeSquareSum(int c) {
    int right = sqrt(c);
    int left = 0;
    while (left < right) {
        long long temp = (long long)(left * left) + (long long)(right * right);
        if (temp < c) {
            left++;
        } else if (temp > c) {
            right--;
        } else {
            return true;
        }
    }
    return false;
}
