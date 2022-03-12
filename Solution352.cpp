//
// Created by luzh on 2021/10/9.
//

#include "Solution352.h"

SummaryRanges::SummaryRanges() {
    cache = {};
}

/**
 * 核心是利用有序键值对存储 left 和 right；
 * 1. l0 <= val <= r0 此时整个区间不发生改变；
 * 2. val = r0 + 1，此时区间更改为[l0, r0 + 1];
 * 3. val = l1 - 1, 此时区间更改为[l1 - 1, r1];
 * 4. 同时满足条件3、 4，此时区间更改为[l0, r1];
 * 5. 不与任何区间相邻，此时区间更改为[val, val];
 * @param val
 */
void SummaryRanges::addNum(int val) {
    map<int, int>::iterator l1 = cache.upper_bound(val);
    map<int, int>::iterator l0 = l1 == cache.begin() ? cache.end() : prev(l1);
    if (l0 == cache.end()) {
        if (val == l1->first - 1) {
            /**
             * 情况3；
             */
            int right = l1->second;
            cache.erase(l1);
            cache.emplace(val, right);
        } else {
            /**
             * 情况5；
             */
            cache.emplace(val, val);
        }
    } else {
        if (val == l0->second + 1 && l1 != cache.end() && val == l1->first - 1) {
            /**
             * 情况4；
             */
            int left = l0->first, right = l1->second;
            cache.erase(l1);
            cache.erase(l0);
            cache.emplace(left, right);
        } else if (val == l0->second + 1){
            /**
             * 情况2；
             */
            l0->second++;
        } else if (l1 != cache.end() && val == l1->first - 1) {
            /**
             * 情况3；
             */
            int right = l1->second;
            cache.erase(l1);
            cache.emplace(val, right);
        } else if (val >= l0->first && val <= l0->second) {
            /*
             * 情况1；
             */
            return;
        } else {
            /**
             * 情况5；
             */
            cache.emplace(val, val);
        }
    }
}

vector<vector<int>> SummaryRanges::getIntervals() {
    vector<vector<int>> ans = {};
    for (auto& [first, second]: cache) {
        ans.push_back({first, second});
    }
    return ans;
}
