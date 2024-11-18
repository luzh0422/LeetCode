//
// Created by luzehui on 2024/5/24.
//

#include "LeetCode1673.h"
#include <stack>

vector<int> LeetCode1673::mostCompetitive(vector<int> &nums, int k) {
//    vector<int> res(k, INT_MAX);
//    int n = nums.size();
//    for (int i = 0; i < n; i++) {
//        int j = k - 1;
//        while (j >= 0 && (k - j - 1) < (n - i) && res[j] > nums[i]) {
//            res[j] = INT_MAX;
//            j--;
//        }
//        if (j != k - 1) {
//            res[++j] = nums[i];
//        }
//    }
//    return res;
    vector<int> res;
    int n = nums.size();
    for (int i = 0; i < n; i++) {
        int num = nums[i];
        if (res.empty() || res.back() <= num) {
            res.push_back(num);
        } else {
            while (!res.empty() && res.back() > num && (res.size() - 1) + (nums.size() - i) >= k) {
                res.pop_back();
            }
            res.push_back(num);
        }
    }
    while (res.size() > k)
        res.pop_back();
    return res;
}
