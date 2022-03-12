//
// Created by luzh on 2022/1/13.
//

#include "Solution747.h"

int Solution747::dominantIndex(vector<int> &nums) {
//    int n = nums.size();
//    int MAX = nums[0];
//    int ans = 0;
//    for (int i = 0; i < n; i++) {
//        int num = nums[i];
//        if (num > MAX) {
//            MAX = num;
//            ans = i;
//        }
//    }
//    for (int i = 0; i < n; i++) {
//        int num = nums[i];
//        if (num < MAX && MAX < num * 2) {
//            return -1;
//        }
//    }
//    return ans;
    int n = nums.size();
    int MAX = INT_MIN, MIDDLE = INT_MIN;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (nums[i] > MAX) {
            MIDDLE = MAX;
            MAX = nums[i];
            ans = i;
        } else if (nums[i] > MIDDLE) {
            MIDDLE = nums[i];
        }
    }
    if (MAX >= 2 * MIDDLE) {
        return ans;
    } else {
        return -1;
    }
}
