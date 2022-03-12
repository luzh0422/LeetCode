//
// Created by luzh on 2021/7/16.
//

#include "SolutionOffer53_I.h"

int SolutionOffer53_I::search(vector<int> &nums, int target) {
    int size = nums.size();
    int left = 0; int right = size - 1;
    int middle = (left + right) / 2;
    int ans = 0;
    while (left < right) {
        if (nums[middle] == target) {
            break;
        } else if (nums[middle] < target) {
            left = middle + 1;
        } else {
            right = middle - 1;
        }
        middle = (left + right) / 2;
    }
    if (middle >= 0 && middle < size && nums[middle] == target) {
        ans = 1;
        for (int i = middle - 1; i >= 0; i--) {
            if (nums[i] == target) {
                ans++;
            } else {
                break;
            }
        }
        for (int i = middle + 1; i < size; i++) {
            if (nums[i] == target) {
                ans++;
            } else {
                break;
            }
        }
    }
    return ans;
}
