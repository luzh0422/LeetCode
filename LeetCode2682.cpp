//
// Created by 陆泽辉 on 2023/8/16.
//

#include "LeetCode2682.h"
#include <unordered_set>

vector<int> LeetCode2682::circularGameLosers(int n, int k) {
    unordered_set<int> uS;
    int curr = 0, step = 1;
    while (!uS.count(curr + 1)) {
        uS.insert(curr + 1);
        curr = (curr + step * k) % n;
        step++;
    }
    vector<int> res;
    for (int i = 1; i <= n; i++) {
        if (!uS.count(i)) {
            res.push_back(i);
        }
    }
    return res;
}
