//
// Created by luzh on 2021/8/23.
//

#include "Solution1646.h"
#include <vector>

int Solution1646::getMaximumGenerated(int n) {
    int ans = INT_MIN;
    if (n <= 0) {
        return 0;
    } else if (n <= 1) {
        return 1;
    } else {
        std::vector<int> cache(n + 1);
        cache[0] = 0;
        cache[1] = 1;
        for (int i = 2; i < n + 1; i++) {
            if (i % 2 == 0) {
                cache[i] = cache[i / 2];
                ans = std::max(ans, cache[i]);
            } else {
                cache[i] = cache[i / 2] + cache[i / 2 + 1];
                ans = std::max(ans, cache[i]);
            }
        }
    }
    return ans;
}

