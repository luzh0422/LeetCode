//
// Created by 陆泽辉 on 2023/10/13.
//

#include "LeetCode1488.h"
#include <stack>

vector<int> LeetCode1488::avoidFlood(vector<int> &rains) {
    int n = rains.size();
    vector<int> ans(n, 1);
    vector<int> cache;
    unordered_map<int, int> uM;
    for (int i = 0; i < n; i++) {
        int rain = rains[i];
        if (rain == 0) {
            cache.push_back(i);
        } else {
            if (uM.count(rain)) {
                if (cache.size() == 0) {
                    return {};
                } else {
                    int oldIndex= uM[rain];
                    auto iter = lower_bound(cache.begin(), cache.end(), oldIndex);
                    if (iter == cache.end()) {
                        return {};
                    }
                    ans[*iter] = rain;
                    cache.erase(iter);
                    uM[rain] = i;
                }
            } else {
                uM.insert(unordered_map<int, int>::value_type(rain, i));
            }
            ans[i] = -1;
        }
    }
    return ans;
}
