//
// Created by luzehui on 2023/12/18.
//

#include "LeetCode162.h"

int LeetCode162::findPeakElement(vector<int> &nums) {
    int n = nums.size();
    auto get = [&](int i) -> pair<int, int> {
        if (i == -1 || i == n) {
            return {0, 0};
        }
        return {1, nums[i]};
    };
    int left = 0, right = n - 1, ans = -1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (get(mid - 1) < get(mid) && get(mid) > get(mid + 1)) {
            ans = mid;
            break;
        }
        if (get(mid) < get(mid + 1)) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return ans;
}
