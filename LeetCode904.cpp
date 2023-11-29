//
// Created by 陆泽辉 on 2022/10/17.
//

#include "LeetCode904.h"

int LeetCode904::totalFruit(vector<int> &fruits) {
    vector<pair<int, int>> vp;
    int n = fruits.size();
    int curr = 0, ret = 0;
    for (int i = 0; i < n; i++) {
        int fruit = fruits[i];
        if (vp.size() < 2) {
            if (vp.size() && vp.front().first == fruit) {
                curr++;
            } else {
                vp.emplace_back(fruit, i);
                curr++;
            }
            ret = curr;
        } else {
            if (vp[1].first == fruit) {
                curr++;
            } else if (vp[0].first == fruit) {
                curr++;
                vp.erase(vp.begin());
                vp.emplace_back(fruit, i);
            } else {
                vp.erase(vp.begin());
                vp.emplace_back(fruit, i);
                curr = i - vp.front().second + 1;
            }
            ret = max(ret, curr);
        }
    }
    return ret;
}
