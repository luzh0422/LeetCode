//
// Created by luzh on 2022/1/19.
//

#include "Solution219.h"
#include <unordered_map>

bool Solution219::containsNearbyDuplicate(vector<int> &nums, int k) {
    unordered_map<int, int> record;
    int n = nums.size();
    for (int i = 0; i < n; i++) {
        int num = nums[i];
        if (record.count(num)) {
            int lastIndex = record[num];
            if (i - lastIndex <= k) {
                return true;
            }
        }
        record[num] = i;
    }
    return false;
}
