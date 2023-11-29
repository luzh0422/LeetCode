//
// Created by 陆泽辉 on 2022/9/20.
//

#include "LeetCode689.h"

#include <numeric>

/**
 * 利用二进制状态压缩法来存储状态
 * 并记录状态，减少运算量；
 * @param nums
 * @param k
 * @return
 */
bool LeetCode689::canPartitionKSubsets(vector<int>& nums, int k) {
    int all = accumulate(nums.begin(), nums.end(), 0);
    if (all % k > 0) {
        return false;
    }
    int per = all / k;
    sort(nums.begin(), nums.end());
    if (nums.back() > per) {
        return false;
    }
    int n = nums.size();
    vector<int> dp(1 << n, true);
    /**
     * s用于二级制状态压缩发记录每个数字是否使用；
     */
    function<bool(int, int)> dfs = [&](int s, int p) -> bool {
        if (s == 0) {
            return true;
        }
        if (p == per) {
            return dfs(s, 0);
        }
        if (p > per) {
            return false;
        }
        if (!dp[s]) {
            return dp[s];
        }
        dp[s] = false;
        for (int i = 0; i < n; i++) {
            if ((s >> i) & 1) {
                s ^= (1 << i);
                if (dfs(s, p + nums[i])) {
                    return true;
                }
                s ^= (1 << i);
            }
        }
        return false;
    };
    return dfs((1 << n) - 1, 0);

//    int all = accumulate(nums.begin(), nums.end(), 0);
//    if (all % k > 0) {
//        return false;
//    }
//    int per = all / k;
//    sort(nums.begin(), nums.end());
//    if (nums.back() > per) {
//        return false;
//    }
//    int n = nums.size();
//    vector<bool> dp(1 << n, true);
//    function<bool(int,int)> dfs = [&](int s, int p)->bool {
//        if (s == 0) {
//            return true;
//        }
//        if (!dp[s]) {
//            return dp[s];
//        }
//        dp[s] = false;
//        for (int i = 0; i < n; i++) {
//            if (nums[i] + p > per) {
//                break;
//            }
//            if ((s >> i) & 1) {
//                if (dfs(s ^ (1 << i), (p + nums[i]) % per)) {
//                    return true;
//                }
//            }
//        }
//        return false;
//    };
//    return dfs((1 << n) - 1, 0);

//  bool DFS(vector<int> &nums, vector<bool> &visit, int start, int target, int curSum, int k) {
//    if (k == 1) {
//        return true;
//    } else if (target == curSum) {
//        return DFS(nums, visit, 0, target, 0, k - 1);
//    } else if (target < curSum) {
//        return false;
//    } else {
//        for (int i = start; i < nums.size(); i++) {
//            if (visit[i] == false) {
//                visit[i] = true;
//                if (DFS(nums, visit, i, target, curSum + nums[i], k))
//                    return true;
//                visit[i] = false;
//            }
//        }
//        return false;
//    }
// }
}

bool LeetCode689::canPartitionKSubsets(vector<int> &nums, int k, int target, vector<int> &cache, int sum, int start) {
    /**
     * 通过K的记录来判断是否递归成功，这种方式才可以遍历所有情况。
     */
    if (k == 0) {
        return true;
    }
    if (sum == target) {
        /**
         * 这个位置很关键，当找到匹配项的时候再重新递归就好了，然后通过cache和k的判断退出递归。
         */
        return canPartitionKSubsets(nums, k - 1, target, cache, 0, 0);
    }
    for (int i = start; i < nums.size(); i++) {
        if (cache[i] == 1) {
            continue;
        }
        sum += nums[i];
        cache[i] = 1;
        if (canPartitionKSubsets(nums, k, target, cache, sum, i + 1)) {
            return true;
        }
        sum -= nums[i];
        cache[i] = 0;
    }
    return false;
}
