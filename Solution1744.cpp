//
// Created by luzh on 2021/6/1.
//

#include "Solution1744.h"

vector<bool> Solution1744::canEat(vector<int> &candiesCount, vector<vector<int>> &queries) {
    /**
     * 求糖果数量的前序和；
     */
    int n = candiesCount.size();
    vector<long long> sum(n);
    sum[0] = candiesCount[0];
    for (int i = 1; i < n; i++) {
        sum[i] = sum[i - 1] + candiesCount[i];
    }
    vector<bool> ans;
    for (int i = 0; i < queries.size(); i++) {
        int favoriteType = queries[i][0];
        int favoriteDay = queries[i][1];
        int dailyCap = queries[i][2];
        /**
         * 每天只吃一颗糖果；
         */
        long long x1 = favoriteDay + 1;
        /**
         * 每天吃最多限制的糖果；
         */
        long long y1 = (long long)(favoriteDay + 1) * dailyCap;
        /**
         * favoriteType的糖果区间；
         */
        long long x2 = (favoriteType == 0) ? 1 : sum[favoriteType - 1] + 1;
        long long y2 = sum[favoriteType];
        ans.push_back(!(x1 > y2 || y1 < x2));
    }
    return ans;
}
