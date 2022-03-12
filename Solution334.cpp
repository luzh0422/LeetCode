//
// Created by luzh on 2022/1/12.
//

#include "Solution334.h"

bool Solution334::increasingTriplet(vector<int> &nums) {
    int MIN = INT_MAX, MIDDLE = INT_MAX;
    int n = nums.size();
    for (int i = 0; i < n; i++) {
        int num = nums[i];
        if (num <= MIN) {
            MIN = num;
        } else if (num <= MIDDLE) {
            MIDDLE = num;
        } else {
            return true;
        }
    }
    return false;
}
