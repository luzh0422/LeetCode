//
// Created by luzh on 2021/7/9.
//

#include "Solution17_10.h"

int Solution17_10::majorityElement(vector<int> &nums) {
    int num = -1;
    int count = 0;
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] == num) {
            count++;
        } else {
            if (count == 0) {
                num = nums[i];
                count = 1;
            } else {
                count--;
            }
        }
    }
    int temp = 0;
    for (int i = 0; i < nums.size(); i++) {
        if (num == nums[i]) {
            temp++;
        }
    }
    if (temp > nums.size() / 2) {
        return num;
    }
    return -1;
}
