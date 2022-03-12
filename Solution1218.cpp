//
// Created by luzh on 2021/11/5.
//

#include "Solution1218.h"
#include <unordered_map>

int Solution1218::longestSubsequence(vector<int> &arr, int difference) {
    int n = arr.size();
    unordered_map<int, int> dp;
    int res = 1;
    for (int i = 0; i < n; i++) {
        if (dp.count(arr[i] - difference)) {
            int temp = dp[arr[i] - difference] + 1;
            res = max(res, temp);
            dp[arr[i]] = temp;
        } else {
            dp[arr[i]] = 1;
        }
    }
    return res;
}
