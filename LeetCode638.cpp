//
// Created by luzehui on 2024/11/8.
//

#include "LeetCode638.h"

int LeetCode638::shoppingOffers(vector<int> &price, vector<vector<int>> &special, vector<int> &needs) {
    int res = 0, n = needs.size();
    for (int i = 0; i < n; i++) {
        res += needs[i] * price[i];
    }
    for (auto &sp : special) {
        if (canUseThisSp(sp, needs)) {
            vector<int> newNeeds(n);
            for (int i = 0; i < n; i++) {
                newNeeds[i] = needs[i] - sp[i];
            }
            res = min(res, sp.back() + shoppingOffers(price, special, newNeeds));
        }
    }
    return res;
}

bool LeetCode638::canUseThisSp(vector<int> &sp, vector<int> &needs) {
    for (int i = 0; i < needs.size(); i++) {
        if (needs[i] < sp[i]) {
            return false;
        }
    }
    return true;
}
