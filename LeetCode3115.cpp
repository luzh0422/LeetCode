//
// Created by luzehui on 2024/7/2.
//

#include "LeetCode3115.h"
#include <functional>

int LeetCode3115::maximumPrimeDifference(vector<int> &nums) {
    function<bool(int)> isPrime = [](int num) -> bool {
        if (num == 1) {
            return false;
        }
        for (int i = 2; i * i < num; i++) {
            if (num % i == 0) {
                return false;
            }
        }
        return true;
    };
    int left = 0, right = nums.size() - 1;
    while (left < right && !isPrime(nums[left])) {
        left++;
    }
    while (left <= right && !isPrime(nums[right])) {
        right--;
    }
    return right - left;
}
