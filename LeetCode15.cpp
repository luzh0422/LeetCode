//
// Created by 陆泽辉 on 2023/7/9.
//

#include "LeetCode15.h"

vector<vector<int>> LeetCode15::threeSum(vector<int> &nums) {
    std::sort(nums.begin(), nums.end());
    vector<vector<int>> res{};
    for (int i = 0; i < nums.size(); i++) {
        if (i >= 1 && nums[i] == nums[i - 1]) {
            continue;
        }
        int target = 0 - nums[i];
        int left = i + 1, right = nums.size() - 1;
        vector<int > arr{};
        while (left < right) {
            if (nums[left] + nums[right] == target) {
                arr.push_back(nums[i]);
                arr.push_back(nums[left]);
                arr.push_back(nums[right]);
                res.push_back(arr);
                arr = {};
                int leftTemp = left + 1;
                while (leftTemp < right && nums[leftTemp] == nums[left]) {
                    leftTemp += 1;
                }
                left = leftTemp;
                int rightTemp = right - 1;
                while (left < rightTemp && nums[rightTemp] == nums[right]) {
                    rightTemp -= 1;
                }
                right = rightTemp;
            } else if (nums[left] + nums[right] < target) {
                int leftTemp = left + 1;
                while (leftTemp < right && nums[leftTemp] == nums[left]) {
                    leftTemp += 1;
                }
                left = leftTemp;
            } else {
                int rightTemp = right - 1;
                while (left < rightTemp && nums[rightTemp] == nums[right]) {
                    rightTemp -= 1;
                }
                right = rightTemp;
            }
        }
    }
    return res;
}
