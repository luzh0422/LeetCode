//
// Created by 陆泽辉 on 2023/8/2.
//

#include "LeetCode822.h"
#include <unordered_set>

int LeetCode822::flipgame(vector<int> &fronts, vector<int> &backs) {
    int res = 3000;
    int n = fronts.size();
    unordered_set<int> uS;
    for (int i = 0; i < n; i++) {
        if (fronts[i] == backs[i]) {
            uS.insert(fronts[i]);
        }
    }
    for (int i = 0; i < n; i++) {
        if (!uS.count(fronts[i])) {
            res = min(res, fronts[i]);
        }
        if (!uS.count(backs[i])) {
            res = min(res, backs[i]);
        }
    }
    return res == 3000 ? 0 : res;
}
