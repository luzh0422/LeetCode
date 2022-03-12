//
// Created by luzh on 2021/10/30.
//

#include "Solution260.h"
#include <set>

vector<int> Solution260::singleNumber(vector<int> &nums) {
    set<int> cache;
    for (auto num: nums) {
        if (cache.count(num)) {
            cache.erase(num);
        } else {
            cache.emplace(num);
        }
    }
    vector<int> ans;
    for (auto key: cache) {
        ans.push_back(key);
    }
    return ans;
}
