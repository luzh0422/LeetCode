//
// Created by luzehui on 25-4-9.
//

#include "LeetCode3375.h"

int LeetCode3375::minOperations(vector<int> &nums, int k) {
    vector<int> records(101, 0);
    int res = 0;
    for (int& num : nums) {
        if (num < k) {
            return -1;
        } else if (num > k && records[num] == 0) {
            res++;
            records[num] = 1;
        }
    }
    return res;
}
