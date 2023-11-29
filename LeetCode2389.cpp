//
// Created by 陆泽辉 on 2023/3/17.
//

#include "LeetCode2389.h"

vector<int> LeetCode2389::answerQueries(vector<int> &nums, vector<int> &queries) {
   std::sort(nums.begin(), nums.end());
   int n = nums.size(), m = queries.size();
   vector<int> res(m, 0), preSum(n + 1, 0);
   for (int i = 0; i < n; i++) {
        preSum[i + 1] = preSum[i] + nums[i];
   }
   for (int i = 0; i < m; i++) {
       int j = 1;
       for (; j <= n; j++) {
           if (preSum[j] > queries[i]) {
               break;
           }
       }
       j--;
       res[i] = j;
   }
   return res;
}
