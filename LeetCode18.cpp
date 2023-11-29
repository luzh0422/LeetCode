//
// Created by 陆泽辉 on 2023/7/15.
//

#include "LeetCode18.h"

vector<vector<int>> LeetCode18::fourSum(vector<int> &nums, int target) {
    int n = nums.size();
    std::sort(nums.begin(), nums.end());
    vector<vector<int>> res{};
    for (int i = 0; i < n; i++) {
        if (i > 0 && nums[i] == nums[i - 1]) {
            continue;
        }
        for (int j = i + 1; j < n; j++) {
            if (j > 1 && nums[j] == nums[j - 1]) {
                continue;
            }
            int temp = target - nums[i] - nums[j];
            int left = j + 1, right = n - 1;
            while (left < right) {
                if (nums[left] + nums[right] == temp) {
                    res.push_back({nums[i], nums[j], nums[left], nums[right]});
                    int leftTemp = left + 1, rightTemp = right - 1;
                    while (leftTemp < rightTemp && nums[leftTemp] == nums[left]) {
                        leftTemp++;
                    }
                    left = leftTemp;
                    while (leftTemp < rightTemp && nums[rightTemp] == nums[right]) {
                        rightTemp--;
                    }
                    right = rightTemp;
                } else if (nums[left] + nums[right] < temp) {
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
