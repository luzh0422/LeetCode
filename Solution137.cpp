//
// Created by luzh on 2021/4/30.
//

#include "Solution137.h"

int Solution137::singleNumber(vector<int> &nums) {
    int ans = 0;
    for (int i = 0; i < 32; i++) {
        int curr = 0;
        for (int j = 0; j < nums.size(); j++) {
            int num = nums[j];
            num = (num >> i) & 1;
            if (num) {
                curr++;
            }
        }
        curr %= 3;
        ans |= (curr << i);
    }
    return ans;
}
