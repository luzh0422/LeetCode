//
// Created by luzh on 2021/7/17.
//

#include "SolutionOffer42.h"

int SolutionOffer42::maxSubArray(vector<int> &nums) {
    int minSum = 0;
    int currSum = 0;
    int ans = INT_MIN;
    for (int i = 0; i < nums.size(); i++) {
        currSum += nums[i];
        ans = max(ans, currSum - minSum);
        minSum = min(currSum, minSum);
    }
    return ans;
}
