//
// Created by luzehui on 2023/10/15.
//

#include "LeetCode137.h"

int LeetCode137::singleNumber(vector<int> &nums) {
    int ans = 0;
    for (int i = 0; i < 32; i++) {
        int curr = 0;
        for (int num : nums) {
            curr += (num >> i) & 1;
        }
        curr %= 3;
        ans |= (curr << i);
    }
    return ans;
}
