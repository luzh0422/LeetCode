//
// Created by luzehui on 2024/10/11.
//

#include "LeetCode3164.h"
#include <unordered_map>

long long LeetCode3164::numberOfPairs(vector<int> &nums1, vector<int> &nums2, int k) {
    unordered_map<int, int> uM;
    for (auto num1 : nums1) {
        for (int i = 1; i * i <= num1; i++) {
            if (num1 % i == 0) {
                uM[i]++;
                if (i * i < num1) {
                    uM[num1 / i]++;
                }
            }
        }
    }
    long long res = 0ll;
    for (auto num2 : nums2) {
        if (uM.count(num2 * k)) {
            res += uM[num2 * k];
        }
    }
    return res;
}
