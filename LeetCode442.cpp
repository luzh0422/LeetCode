//
// Created by 陆泽辉 on 2022/5/8.
//

#include "LeetCode442.h"

/**
 * 如果 nums[i] 恰好出现了一次，那么将 nums[i] 放在数组中下标为 nums[i]−1 的位置即可； 如果 nums[i] 出现了两次，那么我们希望其中的一个 nums[i] 放在数组下标中为 nums[i]−1 的位置，另一个 nums[i] 放置在任意「不冲突」的位置 x。
 * @param nums
 * @return
 */
vector<int> LeetCode442::findDuplicates(vector<int> &nums) {
    int n = nums.size();
    for (int i = 0; i < n; ++i) {
        /**
         * 将nums[i] 放到 nums[i] - 1的位置上；
         */
        while (nums[i] != nums[nums[i] - 1]) {
            swap(nums[i], nums[nums[i] - 1]);
        }
    }
    vector<int> ans;
    for (int i = 0; i < n; ++i) {
        if (nums[i] - 1 != i) {
            ans.push_back(nums[i]);
        }
    }
    return ans;
}
