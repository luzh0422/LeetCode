//
// Created by 陆泽辉 on 2023/10/12.
//

#include "LeetCode2562.h"

long long LeetCode2562::findTheArrayConcVal(vector<int> &nums) {
    auto helper = [](int num) -> int {
        int res = 1;
        while (num != 0) {
            res *= 10;
            num /= 10;
        }
        return res;
    };
    int start = 0, end = nums.size() - 1;
    long long res = 0;
    while (start < end) {
        int temp = helper(nums[end]);
        res += nums[start] * temp + nums[end];
        start++;
        end--;
    }
    if (start == end) {
        res += nums[start];
    }
    return res;
}
