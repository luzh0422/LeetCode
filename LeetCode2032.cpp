//
// Created by 陆泽辉 on 2022/12/29.
//

#include "LeetCode2032.h"

#include <unordered_set>

vector<int> LeetCode2032::twoOutOfThree(vector<int> &nums1, vector<int> &nums2, vector<int> &nums3) {
    unordered_set<int> cache1;
    unordered_set<int> cache2;
    unordered_set<int> cache3;
    for (auto num : nums1) {
        cache1.insert(num);
    }
    for (auto num : nums2) {
        cache2.insert(num);
        if (cache1.count(num)) {
            cache3.insert(num);
        }
    }
    for (auto num : nums3) {
        if (cache1.count(num) || cache2.count(num)) {
            cache3.insert(num);
        }
    }
    vector<int> res(cache3.begin(), cache3.end());
    return res;
}
