//
// Created by luzh on 2021/10/28.
//

#include "Solution869.h"

bool Solution869::reorderedPowerOf2(int n) {
    if (isPowOf2(n)) {
        return true;
    }
    vector<int> nums;
    while (n != 0) {
        int temp = n % 10;
        nums.push_back(temp);
        n /= 10;
    }
    int size = nums.size();
    vector<int> visit(size, false);
    sort(nums.begin(), nums.end());
    for (int i = 0; i < size; i++) {
        if (i > 0 & nums[i] == nums[i - 1]) {
            continue;
        }
        if (nums[i] != 0) {
           visit[i] = true;
           if (backtrack(nums, visit, nums[i], 1)) {
               return true;
           }
           visit[i] = false;
        }
    }
    return false;
}

bool Solution869::backtrack(vector<int> &arr, vector<int> &visit, int curr, int index) {
    int size = arr.size();
    if (index == size) {
        if (isPowOf2(curr)) {
            return true;
        } else {
            return false;
        }
    }
    for (int i = 0; i < size; i++) {
        if (!visit[i]) {
            visit[i] = true;
            if (backtrack(arr, visit, curr * 10 + arr[i], index + 1)) {
                return true;
            }
            visit[i] = false;
        }
    }
    return false;
}

bool Solution869::isPowOf2(int n) {
    return !(n & (n - 1));
}
