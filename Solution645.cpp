//
// Created by luzh on 2021/7/4.
//

#include "Solution645.h"

vector<int> Solution645::findErrorNums(vector<int> &nums) {
    int n = nums.size();
    vector<int> ret;
    vector<int> cache(n + 1, 0);
    for (int i = 1; i < n + 1; i++) {
        cache[nums[i]] ++;
    }
    for (int i = 1; i < n + 1; i++) {
        if (cache[i] == 2) {
            ret.insert(ret.begin(), i);
        } else if (cache[i] == 0) {
            ret.emplace_back(i);
        }
    }
    return ret;
}
