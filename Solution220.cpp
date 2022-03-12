//
// Created by luzh on 2021/4/17.
//

#include "Solution220.h"
#include <set>

bool Solution220::containsNearbyAlmostDuplicate(vector<int> &nums, int k, int t) {
    int n = nums.size();
    /**
     * set容器内的元素会被自动排序，set与map不同，set中的元素既是键值又是实值，set不允许两个元素有相同的键值；
     */
    set<int> rec;
    for (int i = 0; i < n; i++) {
        auto iter = rec.lower_bound(max(nums[i], INT_MIN + t) - t);
        if (iter != rec.end() && *iter <= min(nums[i], INT_MAX - t) + t) {
            return true;
        }
        rec.insert(nums[i]);
        if (i >= k) {
            rec.erase(nums[i - k]);
        }
    }
    return false;
}
