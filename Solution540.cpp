//
// Created by luzh on 2022/2/14.
//

#include "Solution540.h"

int Solution540::singleNonDuplicate(vector<int> &nums) {
    int n = nums.size();
    int left = 0, right = n - 1, middle;
    while (left < right) {
        middle = (left + right) / 2;
        int middleTemp;
        if (middle + 1 < n && nums[middle] == nums[middle + 1]) {
            middleTemp = middle + 1;
            if ((right - middleTemp) % 2 == 0) {
                right = middle - 1;
            } else if ((middle - left) % 2 == 0) {
                left = middleTemp + 1;
            }
        } else if (middle - 1 >= 0 && nums[middle] == nums[middle - 1]) {
            middleTemp = middle - 1;
            if ((right - middle) % 2 == 0) {
                right = middleTemp - 1;
            } else if ((middleTemp - left) % 2 == 0) {
                left = middle + 1;
            }
        } else {
            return nums[middle];
        }
    }
    return nums[left];
}
