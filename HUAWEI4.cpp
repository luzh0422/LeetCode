//
// Created by luzh on 2022/1/12.
//

#include "HUAWEI4.h"

vector<int> HUAWEI4::theMaxSubsequence(vector<int> &nums) {
    int n = nums.size();
    /**
     * 此时输入数组为空，返回 -1作为默认值；
     */
    if (n == 0) {
        return {-1, -1, -1};
    }
    vector<vector<int>> preSums(n, vector<int>(3, 0));
    vector<int> ans(3, 0);
    /**
     * initialize
     * preSums[i][0] 代表左边界；
     * preSums[i][1] 代表右边界；
     * preSums[i][2] 代表以i为结尾的子区间的最大和；
     */
    preSums[0][0] = 1;
    preSums[0][1] = 1;
    preSums[0][2] = nums[0];
    ans[0] = preSums[0][0];
    ans[1] = preSums[0][1];
    ans[2] = preSums[0][2];
    int maxPreSum = nums[0];
    for (int i = 1; i < n; i++) {
        if (preSums[i - 1][2] < 0) {
            preSums[i][0] = i + 1;
            preSums[i][1] = i + 1;
            preSums[i][2] = nums[i];
        } else {
            preSums[i][0] = preSums[i - 1][0];
            preSums[i][1] = i + 1;
            preSums[i][2] = preSums[i - 1][2] + nums[i];
        }
        if (preSums[i][2] > maxPreSum) {
            ans[0] = preSums[i][0];
            ans[1] = preSums[i][1];
            ans[2] = preSums[i][2];
            maxPreSum = preSums[i][2];
        }
    }
    return ans;
}
