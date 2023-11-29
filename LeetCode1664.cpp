//
// Created by 陆泽辉 on 2023/1/28.
//

#include "LeetCode1664.h"

int LeetCode1664::waysToMakeFair(vector<int> &nums) {
    int n = nums.size();
    /**
     * arr[i][0]表示当前位置的偶数位前缀和；
     * arr[i][1]表示当前位置的奇数位前缀和；
     * arr[i][2]表示当前位置的偶数位后缀和；
     * arr[i][3]表示当前位置的奇数位后缀和；
     */
    vector<vector<int>> arr(n + 1, vector<int>(4, 0));
    for (int i = 1; i <= n; i++) {
        if ((i - 1) % 2 == 0) {
            arr[i][0] = arr[i - 1][0] + nums[i - 1];
            arr[i][1] = arr[i - 1][1];
        } else {
            arr[i][0] = arr[i - 1][0];
            arr[i][1] = arr[i - 1][1] + nums[i - 1];
        }
    }
    for (int i = n - 1; i >= 0; i--) {
        if (i % 2 == 0) {
            arr[i][2] = arr[i + 1][2] + nums[i];
            arr[i][3] = arr[i + 1][3];
        } else {
            arr[i][2] = arr[i + 1][2];
            arr[i][3] = arr[i + 1][3] + nums[i];
        }
    }
    int res = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i][0] + arr[i + 1][3] == arr[i][1] + arr[i + 1][2]) {
            res++;
        }
    }
    return res;
}
