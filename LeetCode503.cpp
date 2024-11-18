//
// Created by luzehui on 2024/6/24.
//

#include "LeetCode503.h"
#include <functional>

vector<int> LeetCode503::nextGreaterElements(vector<int> &nums) {
    int n = nums.size();
    vector<int> res(n, -1);
    vector<int> nextStep(n, -1);
    std::function<void(int)> helper = [&](int index) -> void {
        int step = 1;
        while (step < n) {
            int nextIndex = (index + step) % n;
            if (nums[nextIndex] > nums[index]) {
                res[index] = nums[nextIndex];
                nextStep[index] = step;
                break;
            } else {
                if (nextStep[nextIndex] != -1) {
                    step += nextStep[nextIndex];
                } else {
                    step += 1;
                }
            }
        }
    };
    for (int i = 0; i < n; i++) {
        helper(i);
    }
    return res;
}

