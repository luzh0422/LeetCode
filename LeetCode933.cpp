//
// Created by 陆泽辉 on 2022/5/6.
//

#include "LeetCode933.h"

RecentCounter::RecentCounter() {
    pings = {};
}

int RecentCounter::ping(int t) {
    pings.push_back(t);
    auto it = std::lower_bound(pings.begin(), pings.end(), t - 3000);
    return pings.size() - (it - pings.begin());
}
