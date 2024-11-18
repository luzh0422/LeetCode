//
// Created by luzehui on 2024/1/31.
//

#include "LeetCode2670.h"

vector<int> LeetCode2670::distinctDifferenceArray(vector<int> &nums) {
    vector<int> prefix(51, 0);
    vector<int> suffix(51, 0);
    int n = nums.size();
    vector<int> prefixCount(n, 0);
    vector<int> suffixCount(n, 0);
    prefixCount[0] = 1;
    prefix[nums[0]] = 1;
    for (int i = 1; i < n; i++) {
        prefixCount[i] = prefixCount[i - 1];
        if (prefix[nums[i]] == 0) {
            prefixCount[i]++;
            prefix[nums[i]] = 1;
        }
    }
    suffixCount[n - 1] = 0;
    for (int i = n - 2; i >= 0; i--) {
        suffixCount[i] = suffixCount[i + 1];
        if (suffix[nums[i + 1]] == 0) {
            suffixCount[i]++;
            suffix[nums[i + 1]] = 1;
        }
    }
    vector<int> diff(n, 0);
    for (int i = 0; i < n; i++) {
        diff[i] = prefixCount[i] - suffixCount[i];
    }
    return diff;
}
