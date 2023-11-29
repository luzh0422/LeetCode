//
// Created by 陆泽辉 on 2023/6/1.
//

#include "LeetCode2517.h"

int LeetCode2517::maximumTastiness(vector<int> &price, int k) {
    sort(price.begin(), price.end());
    int l = 0, r = price.back() - price.front();
    auto check = [&](int x) -> bool {
        int cnt = 0, pre = -x;
        for (int& curr : price) {
            if (curr - pre >= x) {
                pre = curr;
                ++cnt;
            }
        }
        return cnt >= k;
    };
    while (l < r) {
        int mid = (l + r + 1) >> 1;
        if (check(mid)) {
            l = mid;
        } else {
            r = mid - 1;
        }
    }
    return l;
}
