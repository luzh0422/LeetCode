//
// Created by luzehui on 2024/9/26.
//

#include "LeetCode2535.h"

int LeetCode2535::differenceOfSum(vector<int> &nums) {
    long long sum1 = 0, sum2 = 0;
    for (int num : nums) {
        sum1 += num;
        sum2 += bytesSum(num);
    }
    return abs(sum1 - sum2);
}

int LeetCode2535::bytesSum(int num) {
    int sum = 0;
    while (num != 0) {
       sum += num % 10;
       num /= 10;
    }
    return sum;
}
