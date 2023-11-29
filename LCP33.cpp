//
// Created by 陆泽辉 on 2023/5/21.
//

#include "LCP33.h"

int LCP33::storeWater(vector<int> &bucket, vector<int> &vat) {
    int mx = *max_element(vat.begin(), vat.end());
    if (mx == 0) {
        return 0;
    }
    int n = vat.size();
    int ans = INT_MAX;
    /**
     * mx表示最多需要蓄水多少次；
     */
    for (int x = 1; x <= mx; x++) {
        int y = 0;
        /**
         * 当蓄水次数为x次时，所有水桶需要添加的次数；
         */
        for (int i = 0; i < n; ++i) {
            /**
             * (vat[i] + x - 1) / x表示向上取整；
             */
            y += max(0, (vat[i] + x - 1) / x - bucket[i]);
        }
        ans = min(ans, x + y);
    }
    return ans;
}
