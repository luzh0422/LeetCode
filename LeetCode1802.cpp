//
// Created by 陆泽辉 on 2023/1/4.
//

#include "LeetCode1802.h"

#include <algorithm>

int LeetCode1802::maxValue(int n, int index, int maxSum) {
    int left = 1, right = maxSum;
    long middle = (left + right) / 2;
    long res = -1;
    while (left <= right) {
        middle = (left + right) / 2;
        long leftSum = 0;
        int leftLength = index;
        long leftVal = middle - 1;
        if (leftLength > 0) {
            leftSum += (leftVal + 1) * leftVal / 2;
            if (leftVal > leftLength) {
                long leftTemp = (leftVal - leftLength);
                leftSum -= (leftTemp + 1) * leftTemp / 2;
            } else if (leftVal < leftLength) {
                leftSum += (leftLength - leftVal);
            }
        }
        long rightSum = 0;
        int rightLength = n - index - 1;
        long rightVal = middle - 1;
        if (rightLength > 0) {
            rightSum += (rightVal + 1) * rightVal / 2;
            if (rightVal > rightLength) {
                long rightTemp = (rightVal - rightLength);
                rightSum -= (rightTemp + 1) * rightTemp / 2;
            } else if (rightVal < rightLength) {
                rightSum += (rightLength - rightVal);
            }
        }
        long temp = leftSum + rightSum + middle;
        if (temp > maxSum) {
            right = middle - 1;
        } else if (temp < maxSum) {
            left = middle + 1;
            res = std::max(res, middle);
        } else {
            return middle;
        }
    }
    return res;
}
