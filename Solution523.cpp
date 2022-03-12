//
// Created by luzh on 2021/6/2.
//

#include "Solution523.h"
#include <unordered_map>

bool Solution523::checkSubarraySum(vector<int> &nums, int k) {
    int size = nums.size();
    vector<int> preSum(size + 1);
    unordered_map<int, int> cache = {};
    preSum[0] = 0;
    for (int i = 0; i < size; i++) {
        preSum[i + 1] = preSum[i] + nums[i];
        int temp = preSum[i + 1] % k;
        if (temp == 0 && i > 0) {
            return true;
        }
        if (cache.count(temp) && k - cache[temp] > 1) {
            if ((preSum[i + 1] - preSum[cache[temp] + 1]) % k == 0) {
                return true;
            }
            cache[temp] = i;
        } else {
            cache.insert(unordered_map<int, int>::value_type(temp, i));
        }
    }
    return false;
}
