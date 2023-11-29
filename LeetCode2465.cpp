//
// Created by 陆泽辉 on 2023/6/4.
//

#include "LeetCode2465.h"
#include <unordered_set>

int LeetCode2465::distinctAverages(vector<int> &nums) {
    unordered_set<float> uS;
    std::sort(nums.begin(), nums.end());
    int left = 0, right = nums.size() - 1;
    while (left < right) {
        float temp = float(nums[left] + nums[right]) / 2.0f;
        uS.insert(temp);
    }
    return uS.size();
}
