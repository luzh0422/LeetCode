//
// Created by luzehui on 2023/10/15.
//

#include "LeetCode260.h"

/**
 * 由于数组中存在两个数不相同，要将两个数分到两个不同种类中，这样每个种类中只有一个数，就可以通过异或来处理了。
 * @param nums
 * @return
 */
vector<int> LeetCode260::singleNumber(vector<int> &nums) {
    int total = 0;
    for (int& num : nums) {
        total ^= num;
    }
    int l = 1;
    while ((l & total) == 0) {
        l <<= 1;
    }
    int num1 = 0, num2 = 0;
    for (int& num : nums) {
        if ((num & l) > 0) {
            num1 ^= num;
        } else {
            num2 ^= num;
        }
    }
    return {num1, num2};
}
