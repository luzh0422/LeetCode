//
// Created by luzh on 2021/12/29.
//

#include "Solution1995.h"
#include <unordered_map>

/**
 * 这个算法只能求解连续数组，而题目中的内容并不一定是连续数组；
 */
//int Solution1995::countQuadruplets(vector<int> &nums) {
//    int n = nums.size();
//    vector<int> sums(n + 1);
//    sums[0] = 0;
//    int sum = 0;
//    int ans = 0;
//    for (int i = 0; i < n; i++) {
//        sum += nums[i];
//        if (i > 2) {
//            if (sums[i] - sums[i - 3] == nums[i]) {
//                ans++;
//            }
//        }
//        sums[i + 1] = sum;
//    }
//    return ans;
//}

int Solution1995::countQuadruplets(vector<int> &nums) {
    int n = nums.size();
    unordered_map<int, int> uM;
    int ans = 0;
    for (int i = n - 2; i >= 0; i--) {
        if (uM.count(nums[i + 1])) {
            uM[nums[i + 1]]++;
        } else {
            uM[nums[i + 1]] = 1;
        }
        for (int j = 0; j < i; j++) {
            for (int k = j + 1; k < i; k++) {
                int sum = nums[i] + nums[j] + nums[k];
                if (uM.count(sum)) {
                    ans += uM[sum];
                }
            }
        }
    }
    return ans;
}
