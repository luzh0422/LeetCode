//
// Created by 陆泽辉 on 2023/7/8.
//

#include "LeetCode167.h"

vector<int> LeetCode167::twoSum(vector<int> &numbers, int target) {
    int left = 0, right = numbers.size() - 1;
    while (left < right) {
        int curr = numbers[left] + numbers[right];
        if (curr < target) {
            left++;
        } else if (curr > target) {
            right--;
        } else {
            return {left, right};
        }
    }
    return {};
}
