//
// Created by 陆泽辉 on 2022/6/16.
//

#include "LeetCode532.h"
#include <unordered_set>
#include <unordered_map>

int LeetCode532::findPairs(vector<int> &nums, int k) {
    unordered_map<int, int> uM;
    for (auto num : nums) {
        if (uM.count(num)) {
            uM[num]++;
        } else {
            uM.insert(unordered_map<int, int>::value_type (num, 1));
        }
    }
    int ret = 0;
    unordered_set<int> rets;
    if (k == 0) {
        for (auto it = uM.begin(); it != uM.end(); it++) {
            if (it->second > 1) {
                ret++;
            }
        }
        return ret;
    }
    for (auto num: nums) {
        int temp = num - k;
        if (uM.count(temp) && !rets.count(num)) {
            rets.insert(num);
            ret++;
        }
    }
    return ret;
}
