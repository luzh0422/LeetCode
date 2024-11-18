//
// Created by luzehui on 2024/11/6.
//

#include "LeetCode3254.h"

vector<int> LeetCode3254::resultsArray(vector<int> &nums, int k) {
    int n = nums.size();
    vector<int> res(n - k + 1, -1);
    if (k == 1) {
        for (int i = 0; i < n; i++) {
            res[i] = nums[i];
        }
        return res;
    }
    bool tag = true;
    for (int i = 0; i < k - 1; i++) {
        if (nums[i + 1] != nums[i] + 1) {
            tag = false;
            break;
        }
    }
    if (tag) {
        res[0] = nums[k - 1];
    } else {
        res[0] = -1;
    }
    for (int i = 1; i < n - k + 1; i++) {
        if (res[i - 1] != -1) {
            if (nums[i + k - 1] == nums[i + k - 2] + 1) {
                res[i] = nums[i + k - 1];
            } else {
                res[i] = -1;
            }
        } else {
            tag = true;
            for (int j = i + k - 1; j > i; j--) {
                if (nums[j] != nums[j - 1] + 1) {
                    tag = false;
                    break;
                }
            }
            if (tag) {
                res[i] = nums[i + k - 1];
            } else {
                res[i] = -1;
            }
        }
    }
    return res;
}
