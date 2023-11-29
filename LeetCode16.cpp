//
// Created by 陆泽辉 on 2023/7/10.
//

#include "LeetCode16.h"

int LeetCode16::threeSumClosest(vector<int> &nums, int target) {
    std::sort(nums.begin(), nums.end());
    int dis = INT_MAX;
    int res = -1;
    for (int i = 0; i < nums.size(); i++) {
        if (i >= 1 && nums[i] == nums[i - 1]) {
            continue;
        }
        int left = i + 1;
        int right = nums.size() - 1;
        while (left < right) {
            int sum = nums[left] + nums[right] + nums[i];
            if (target == sum) {
                return sum;
            } else {
                int currDis = abs(target - sum);
                if (currDis < dis) {
                    dis = currDis;
                    res = sum;
                }
                if (sum < target) {
                    int leftTemp = left + 1;
                    while (leftTemp < right && nums[leftTemp] == nums[left]) {
                        leftTemp++;
                    }
                    left = leftTemp;
                } else {
                    int rightTemp = right - 1;
                    while (left < rightTemp && nums[rightTemp] == nums[right]) {
                        rightTemp--;
                    }
                    right = rightTemp;
                }
            }
        }
    }
    return res;
}
