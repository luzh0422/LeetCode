//
// Created by 陆泽辉 on 2022/8/29.
//

#include "LeetCode1470.h"

vector<int> LeetCode1470::shuffle(vector<int> &nums, int n) {
   int left = 0, right = n + 1;
   vector<int> ret(2 * n, 0);
   for (int i = 0; i < 2 * n; i += 2) {
        ret[i] = nums[left];
        ret[i + 1] = nums[right];
        left++;
        right++;
   }
   return ret;
}
