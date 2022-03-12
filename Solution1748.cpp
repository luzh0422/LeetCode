//
// Created by luzh on 2022/2/6.
//

#include "Solution1748.h"
#include <unordered_map>

int Solution1748::sumOfUnique(vector<int> &nums) {
    int ans = 0;
    int n = nums.size();
    unordered_map<int, int> um;
    for (int i = 0; i < n; i++) {
        int num = nums[i];
        if (um.count(num)) {
            if (um[num] == 1) {
                ans -= num;
            }
            um[num]++;
        } else {
            ans += num;
            um.insert(unordered_map<int, int>::value_type (num, 1));
        }
    }
    return ans;
}
