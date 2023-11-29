//
// Created by 陆泽辉 on 2023/2/16.
//

#include "LeetCode2341.h"
#include <unordered_set>

vector<int> LeetCode2341::numberOfPairs(vector<int> &nums) {
    int count = 0;
    unordered_set<int> uS;
    int n = nums.size();
    for (int i = 0; i < n; i++) {
        int num = nums[i];
        if (uS.count(num)) {
            count++;
            uS.erase(num);
        } else {
            uS.insert(num);
        }
    }
    return {count, n - 2 * count};
}
