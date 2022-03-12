//
// Created by luzh on 2021/5/28.
//

#include "Solution477.h"

int Solution477::totalHammingDistance(vector<int> &nums) {
    int size = nums.size();
    int ans = 0;
    for (int i = 0; i < 30; i++) {
        int c = 0;
        for (int j = 0; j < size; j++) {
            int num = nums[j];
            c += (num >> i) & 1;
        }
        ans += (size - c) * c;
    }
    return ans;
}
